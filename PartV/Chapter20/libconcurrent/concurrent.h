#ifndef CONCURRENT_H
#define CONCURRENT_H

#include <iostream>
#include <thread>
#include <mutex>
#include <exception>
#include <condition_variable>
#include <atomic>
#include <stack>
#include <queue>
#include <future>
#include "config.h"

void compile_time()
{
	std::cout <<__TIME__<<std::endl;
}
void version()
{
	std::cout<<CONCURRENT_PRIMER_VERSION_MAJOR<<"."<<CONCURRENT_PRIMER_VERSION_MINOR<<std::endl;
}



// ====================================================================
class thread_guard
{
	private:
		std::thread t;
	public:
		thread_guard()=delete;
		explicit  thread_guard(std::thread t_);
		thread_guard(const thread_guard&)=delete;
		thread_guard& operator=(const thread_guard& tg)=delete;
		~thread_guard();
};



// ====================================================================
class spinlock_mutex
{
	private:
		std::atomic_flag flag;
	public:
		spinlock_mutex();
		void lock();
		void unlock();
};
// ====================================================================


struct empty_stack: std::exception
{
	const char* what() const throw()
	{
		return "empty stack";
	}
};

// =================== threadsafe_stack begin =============
template <typename T>
class threadsafe_stack
{
	private:
		std::stack<T> data;
		mutable std::mutex m;
	public:
		threadsafe_stack() {}
		threadsafe_stack(const threadsafe_stack& other)
		{
			std::lock_guard<std::mutex> lock(other.m);
			data = other.data;
		}
		threadsafe_stack& operator=(const threadsafe_stack& ) = delete;

		void push(T& new_value)
		{
			std::lock_guard<std::mutex> lock(m);
			data.push(std::move(new_value));
		}
	
		std::shared_ptr<T> pop()
		{
			std::lock_guard<std::mutex> lock(m);
			if(data.empty())
			{
				throw empty_stack();
			}
			std::shared_ptr<T> const res(std::make_shared<T>(std::move(data.top())));
			data.pop();
			return res;
		}

		void pop(T& value)
		{
			std::lock_guard<std::mutex> lock(m);
			if(data.empty())
			{
				throw empty_stack();
			}
			value = std::move(data.top());
			data.pop();
		}

		bool empty() const
		{
			std::lock_guard<std::mutex> lock(m);
			return data.empty();
		}
};

// =================== threadsafe_stack end ===============
// =================== threadsafe_queue begin =============
template <typename T>
class threadsafe_queue
{
	private:
		mutable std::mutex mut;
		std::queue<T> data_queue;
		std::condition_variable data_cond;
	public:
		threadsafe_queue()
		{}

		void push(T new_value)
		{
			std::lock_guard<std::mutex> lock(mut);
			data_queue.push(std::move(new_value));
			data_cond.notify_one();
		}

		void wait_and_pop(T& value)
		{
			std::unique_lock<std::mutex> lock(mut);
			data_cond.wait(lock, [this](){return !data_queue.empty();});
			value=std::move(data_queue.front());
			data_queue.pop();

		}

		std::shared_ptr<T> wait_and_pop()
		{
			std::unique_lock<std::mutex> lock(mut);
			data_cond.wait(lock, [this](){return !data_queue.empty();});
			std::shared_ptr<T> res(
					std::make_shared<T>(std::move(data_queue.front()))
					);
			data_queue.pop();
			return res;
		}

		bool try_pop(T& value)
		{
			std::lock_guard<std::mutex> lock(mut);
			if(data_queue.empty())
			{
				return false;
		
			}
			value=std::move(data_queue.front());
			data_queue.pop();
			return true;
		}

		std::shared_ptr<T> try_pop()
		{
			std::lock_guard<std::mutex> lock(mut);
			if(data_queue.empty())
			{
				return std::shared_ptr<T>();
			}
			std::shared_ptr<T> res(
					std::make_shared<T>(std::move(data_queue.front()))
					);
			data_queue.pop();
			return res;
		}

		bool empty() const
		{
			std::lock_guard<std::mutex> lock(mut);
			return data_queue.empty();
		}

};
// =================== threadsafe_queue end ===============
// =================== thread pool begin ==================

class join_threads
{
	private:
		std::vector<std::thread>& threads;
	public:
		explicit join_threads(std::vector<std::thread>& threads_): threads(threads_)
		{}

		~join_threads()
		{
			for(auto it = threads.begin(); it != threads.end(); it++)
			{
				if(it->joinable())
				{
					it->join();
				}
			}
		}
};

class function_wrapper
{
	private:
		struct impl_base{
			virtual void call() = 0;
			virtual ~impl_base() {}
		};

		template <typename F>
		struct impl_type: impl_base
		{
			F f;
			impl_type(F&& f_) : f(std::move(f_))
			{}
			void call() {f();}
		};

		std::unique_ptr<impl_base> impl;
	public:
		template <typename F>
		function_wrapper(F&& f): impl(new impl_type<F>(std::move(f)))
		{}

		function_wrapper() = default;
		
		function_wrapper(function_wrapper&& other): impl(std::move(other.impl))
		{
		}

		function_wrapper(const function_wrapper&)=delete;
		function_wrapper(function_wrapper&)=delete;
		function_wrapper& operator=(function_wrapper&& other)
		{
			impl=std::move(other.impl);
			return *this;
		}
		function_wrapper& operator=(function_wrapper&)=delete;

		void operator()()
		{
			impl->call();
		}
};

class thread_pool
{
	private:
		std::atomic_bool done;
		threadsafe_queue<function_wrapper> work_queue;
		std::vector<std::thread> threads;
		join_threads joiner;

		void worker_thread()
		{
			while(!done)
			{
				run_pending_task();
			}
		}
	public:

		thread_pool(): done(false), joiner(threads)
		{
			unsigned const thread_count = std::thread::hardware_concurrency();
			try
			{
				for(unsigned i=0; i<thread_count;i++)
				{
					threads.push_back(
								std::thread(&thread_pool::worker_thread, this)
							);
				}
			}
			catch(...)
			{
				done = true;
				throw;
			}
			
		}

		~thread_pool()
		{
			done=true;
		}

		template <typename FunctionType>
		std::future<typename std::result_of<FunctionType()>::type> submit(FunctionType f)
		{
			typedef typename std::result_of<FunctionType()>::type result_type;

			std::packaged_task<result_type()> task(std::move(f));
			std::future<result_type> res(task.get_future());
			work_queue.push(std::move(task));
			return res;
		}

		void run_pending_task()
		{
			function_wrapper task;
			if(work_queue.try_pop(task))
			{
				task();
			}
			else
			{
				std::this_thread::yield();
			}
		}
};
// =================== thread pool end ====================
// =================== thread pool begin ====================
class interrupt_flag;
extern thread_local interrupt_flag this_thread_interrupt_flag;

struct thread_interrupted: std::exception
{
	const char* what() const throw()
	{
		return "thread interrupted";
	}
};


class interrupt_flag
{
	private:
		std::atomic<bool> flag;
		std::condition_variable* thread_cond;
		std::mutex set_clear_mutex;
	public:
		interrupt_flag(): thread_cond(0)
		{}
		void set()
		{
			flag.store(true, std::memory_order_relaxed);
			std::lock_guard<std::mutex> lk(set_clear_mutex);
			if(thread_cond)
			{
				thread_cond->notify_all();
			}
		}
		bool is_set()
		{
			return flag.load(std::memory_order_relaxed);
		}

		void set_condition_variable(std::condition_variable& cv)
		{
			std::lock_guard<std::mutex> lk(set_clear_mutex);
			thread_cond = &cv;
		}
		void clear_condition_variable()
		{
			std::lock_guard<std::mutex> lk(set_clear_mutex);
			thread_cond = 0;
		}

		struct clear_cv_on_destruct
		{
			~clear_cv_on_destruct()
			{
				this_thread_interrupt_flag.clear_condition_variable();
			}
		};
};

thread_local interrupt_flag this_thread_interrupt_flag;
class interruptible_thread
{
	private:
		std::thread internal_thread;
		interrupt_flag* flag;

	public:
		template <typename FunctionType>
		interruptible_thread(FunctionType f)
		{
			std::promise<interrupt_flag*> p;
			internal_thread = std::thread(
						[f,&p](){
									p.set_value(&this_thread_interrupt_flag);
									try
									{
										f();
									}
									catch(thread_interrupted const&)
									{
									}

						}
					);
			flag = p.get_future().get();
		}

		void interrupt()
		{
			if(flag)
			{
				flag->set();
			}
		}

		void join()
		{
			internal_thread.join();
		}

		bool joinable() const
		{
			return internal_thread.joinable();
		}
};

void interruption_point()
{
	if(this_thread_interrupt_flag.is_set())
	{
		throw thread_interrupted();
	}
}

template <typename Predicate>
void interruptible_wait(std::condition_variable& cv, std::unique_lock<std::mutex>& lk, Predicate pred)
{
	interruption_point();
	this_thread_interrupt_flag.set_condition_variable(cv);
	interrupt_flag::clear_cv_on_destruct guard;
	while(!this_thread_interrupt_flag.is_set()&&!pred())
	{
		cv.wait_for(lk, std::chrono::milliseconds(1));
	}
	interruption_point();
}



// =================== thread pool end ====================
#endif /* ifndef CONCURRENT_H */

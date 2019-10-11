#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int count;


template <typename T>
class threadsafe_queue
{
	private:
		mutable mutex mut;
		queue<T> data_queue;
		condition_variable data_cond;
	public:
		threadsafe_queue(){}
		threadsafe_queue(const threadsafe_queue& other)
		{
			lock_guard<mutex> lk(other.mut);
			data_queue = other.data_queue;
		}

		void push(T value)
		{
			lock_guard<mutex> lk(mut);
			data_queue.push(value);
			data_cond.notify_one();
		}

		void wait_and_pop(T& value)
		{
			unique_lock<mutex> lk(mut);
			data_cond.wait(lk, [this](){return !data_queue.empty();});
			value = data_queue.front();
			data_queue.pop();
		}

		shared_ptr<T> wait_and_pop()
		{
			unique_lock<mutex> lk(mut);
			data_cond.wait(lk, [this](){return !data_queue.empty();});
			shared_ptr<T> res(make_shared<T>(data_queue.front()));
			data_queue.pop();
			return res;
		}

		bool try_pop(T& val)
		{
			lock_guard<mutex> lk(mut);
			if(data_queue.empty())
				return false;
			val = data_queue.front();
			data_queue.pop();
			return true;
		}

		shared_ptr<T> try_pop()
		{
			lock_guard<mutex> lk(mut);
			if (data_queue.empty()) 
			{
				return shared_ptr<T>();	
			}

			shared_ptr<T> res(make_shared<T>(data_queue.front()));
			data_queue.pop();
			return res;
		}

		bool empty() const
		{
			lock_guard<mutex> lk(mut);
			return data_queue.empty();
		}
		unsigned int size() const
		{
			lock_guard<mutex> lk(mut);
			return data_queue.size();
		}

};


template <typename T>
void thread_send(threadsafe_queue<T>& q)
{
	while(1)
	{
		count++;
		q.push(count);
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

template <typename T>
void thread_receive(threadsafe_queue<T>& q)
{
	while(1)
	{
		int val;
		q.wait_and_pop(val);
		cout << "id: " << this_thread::get_id() <<" : " << val <<endl;
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

template <typename T>
void thread_report_size(threadsafe_queue<T>& q)
{
	while(1)
	{
		auto sz = q.size();
		cout << "queue size: " << sz << endl;
		this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
class thread_guard
{
	private:
		thread t;
	public:
		explicit thread_guard(thread t_): t(std::move(t_))
		{
			if(!t.joinable())
				throw logic_error("No Thread");
		}
		~thread_guard()
		{
			t.join();
		}
		thread_guard(const thread_guard&) = delete;
		thread_guard& operator=(const thread_guard&) = delete;
};

int main(int argc, char *argv[])
{
	threadsafe_queue<int> q;
	thread_guard tr1(thread{thread_receive<int>, std::ref(q)});
	thread_guard tr2(thread{thread_receive<int>, std::ref(q)});
	thread_guard ts(thread{thread_send<int>, std::ref(q)});
	thread_guard ts1(thread{thread_send<int>, std::ref(q)});
	thread_guard ts2(thread{thread_send<int>, std::ref(q)});
	thread_guard tr(thread{thread_report_size<int>, std::ref(q)});
	return 0;
}

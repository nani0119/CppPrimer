#include <iostream>
#include <string>
#include <stack>
#include <thread>
#include <mutex>
#include <exception>
#include <unistd.h>
#include <vector>
#include <map>
using namespace std;
// #define DEBUG

struct empty_stack: std::exception
{
	const char* what() const throw()
	{
		return "empty stack";
	}
};


template <typename T>
class threadsafe_stack
{
	private:
		stack<T> data;
		mutex m;
	public:
		threadsafe_stack(){}
		threadsafe_stack(const threadsafe_stack& other)
		{
			lock_guard<mutex> lock(other.m);
			data = other.data;
		}
		threadsafe_stack& operator=(const threadsafe_stack& ) = delete;

		size_t size()
		{
			lock_guard<mutex> lock(m);
			auto sz =  data.size();
// #ifdef DEBUG
			cerr << "stack size:" << sz <<endl;
// #endif
			return sz;
		}
		bool empty()
		{
			lock_guard<mutex> lock(m);
			return data.empty();
		}

		void push(T& value)
		{
			lock_guard<mutex> lock(m);
#ifdef DEBUG
			cout << "push:"<< value << endl;
#endif
			data.push(value);
		}

		void pop(T& value)
		{
			lock_guard<mutex> lock(m);
			if(data.empty())
				throw empty_stack();
			value = data.top();
#ifdef DEBUG
			cout << "pop :" << value << endl;
#endif
			data.pop();
		}

		shared_ptr<T> pop()
		{
			lock_guard<mutex> lock(m);
			if (data.empty())
				throw empty_stack();
			shared_ptr<T> res(make_shared<T>(data.top()));
			data.pop();
#ifdef DEBUG
			cout << "pop :" << *res << endl;
#endif
			return res;
		}

};

class thread_guard
{
	private:
		thread t;
	public:
		explicit thread_guard(thread t_): t(std::move(t_))
		{
			if(!t.joinable())
				throw logic_error("No thread");
		}
		~thread_guard()
		{
			t.join();
		}
		thread_guard(const thread_guard&) = delete;
		thread_guard& operator=(const thread_guard& ) = delete;
};

template <typename T>
class producter
{
	private:
		T value;
	public:
	producter() = default;
	producter(T val): value(val) 
	{

	}
	void operator()(threadsafe_stack<T>& stk)
	{
		while(1)
		{
			stk.push(value);
			// cout <<endl<< "producter push:" << value;
			value++;
		}

	}	
};

template <typename T>
class constumer
{
	public:
		void operator()(threadsafe_stack<T>& stk)
		{
			while(1)
			{
				if(!stk.empty())
				{
					T val;
					stk.pop(val);
					// cout<<endl << "constumer pop:" << val;
				}
			}
		}
};


template <typename T>
class constumer_helper
{
	private:
		map<thread::id,thread> thread_set;
		int thread_cnt;
	public:
		constumer_helper(): thread_cnt(thread::hardware_concurrency() - 4)
		{
			if(thread_cnt < 0)
				thread_cnt = 0;
		}
		void operator()(threadsafe_stack<T>& stk)
		{
			auto f = [&](threadsafe_stack<T>& stk) -> void {
																while(stk.size() > 2000)  \
																	{stk.pop();}  \
																thread_set.erase(this_thread::get_id()); \
																thread_cnt++; \
																cout << "exit thread <<<<<<<<<"<<endl; \
															};
			while(1)
			{
				auto sz = stk.size();
				if(sz > 5000 && thread_cnt > 0)
				{
					thread_cnt--;
					cout << ">>>>>>>> creat thread" << endl;
					thread t(f,std::ref(stk));
					t.detach();
					thread_set.emplace(t.get_id(),std::move(t));
				}
			}
		}
};

int main(int argc, char *argv[])
{
	int i = 0;
	threadsafe_stack<int> stk;
	thread_guard tp(thread(producter<int>(i), std::ref(stk)));
	thread_guard tp1(thread(producter<int>(i), std::ref(stk)));
	thread_guard tc(thread(constumer<int>(), std::ref(stk)));
	thread_guard ts(thread(constumer_helper<int>(), std::ref(stk)));
	return 0;
}

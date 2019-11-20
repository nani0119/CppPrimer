#include <iostream>
#include <string>
#include <exception>
#include <thread>
#include <atomic>

using namespace std;

class spinlock_mutex
{
	atomic_flag flag;

	public:
	spinlock_mutex():flag(ATOMIC_FLAG_INIT)
	{}

	void lock()
	{
		while(flag.test_and_set(memory_order_acquire))
		{}
	}

	void unlock()
	{
		flag.clear(memory_order_acquire);
	}
};

class thread_guard
{
	private:
		thread t;
	public:
		explicit thread_guard(thread t_) : t(std::move(t_))
		{
			if(!t.joinable())
			{
				throw logic_error("No thread");
			}
		}
		thread_guard(const thread_guard&) = delete;
		thread_guard& operator=(const thread_guard&) = delete;

		~thread_guard()
		{
			t.join();
		}
};

spinlock_mutex spin_mutex;

void func(int i)
{
	spin_mutex.lock();
	while(1)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "thread id: "<<std::this_thread::get_id() <<" "<<i << endl;
	}
	spin_mutex.unlock();
}

class func_obj
{
	public:
		void operator()(int i)
		{
			spin_mutex.lock();
			while(1)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				cout << "thread id: "<<std::this_thread::get_id()<< " "<<i << endl;
			}
			spin_mutex.unlock();
		}
};


int main(int argc, char *argv[])
{
	int i = 0;
	thread_guard tf(thread(func,i));
	i++;
	thread tfo{func_obj(),i};
	thread_guard tfog(std::move(tfo));

	i++;
	thread_guard tfl(thread([](int i)->void { \
				spin_mutex.lock(); \
				while(1) \
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(1000)); \
					cout << "thread id: "<<std::this_thread::get_id()<< " "<<i << endl; \
				}
				spin_mutex.unlock(); \
				 },i));
	return 0;
}

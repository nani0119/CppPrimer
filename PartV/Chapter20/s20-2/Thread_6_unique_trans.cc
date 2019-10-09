#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <exception>
#include <unistd.h>
#include <random>
#include <ctime>

using namespace std;
unsigned long val = 0;

mutex global_mutex;

int random_num()
{
	static default_random_engine e(time(0));
	static uniform_int_distribution<int> u(0,6);
	return u(e);
}


void prepare_data()
{
	cout <<"id "<<this_thread::get_id()<<endl;
	cout <<"1 "<<__func__<<endl;
	val++;
}
unique_lock<mutex> getlock()
{
	unique_lock<mutex> lk(global_mutex);
	prepare_data();
	return lk;
}

void process_data()
{
	unique_lock<mutex> lk(::getlock());
	cout <<"2 "<< __func__ <<endl;
	cout <<"3 "<< val << endl;
}
void func()
{
	while(1)
	{
		process_data();
		sleep(random_num());
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
			{
				throw logic_error("No Thread");
			}
		}
		thread_guard(const thread_guard&) = delete;
		thread_guard& operator=(const thread_guard&) = delete;
		~thread_guard()
		{
			t.join();
		}
};


int main(int argc, char *argv[])
{
#if 1
	 thread_guard t1(thread{func});
	 thread_guard t2(thread{func});
	 thread_guard t3(thread{func});
	 thread_guard t4(thread{func});
	 thread_guard t5(thread{func});
	 thread_guard t6(thread{func});
#else
	 thread t1(func);
	 thread t2(func);
	 t1.join();
	 t2.join();
#endif

	 return 0;
}

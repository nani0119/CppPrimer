#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <exception>
#include <unistd.h>
#include <climits>

using namespace std;

class hierarchical_mutex
{
	private:
		mutex internal_mutex;
		unsigned long const hierarchy_value; // 锁级别，变量持有
		unsigned long previous_hierarchy_value; // unlock 恢复适用
		static thread_local unsigned long this_thread_hierarchy_value; //　线程持有， thread_local 声明的变量每个线程有且只有一份变量副本，保存当前线程持有的锁级别
		void check_for_hierarchy_violation()
		{
			if(this_thread_hierarchy_value <= hierarchy_value) // 只能申请比本线程级别低的锁
			{
				throw std::logic_error("mutex hierarchy violated");
			}
		}
		void update_hierarchy_value()
		{
			previous_hierarchy_value=this_thread_hierarchy_value;
			this_thread_hierarchy_value=hierarchy_value;
		}
	public:
		explicit hierarchical_mutex(unsigned long value):hierarchy_value(value),previous_hierarchy_value(0)
		{

		}

		void lock()
		{
			check_for_hierarchy_violation();
			internal_mutex.lock();
			update_hierarchy_value();
		}

		void unlock()
		{
			this_thread_hierarchy_value=previous_hierarchy_value;
			internal_mutex.unlock();
		}

		bool try_lock()
		{	
			check_for_hierarchy_violation();
			if(!internal_mutex.try_lock())
				return false;
			update_hierarchy_value();
			return true;
		}
};

thread_local unsigned long hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX);
hierarchical_mutex high_level_mutex(10000);
hierarchical_mutex low_level_mutex(5000);

int do_low_level_stuff()
{
	cout << __func__ << endl;
	return 10;
}

int low_level_func()
{
	std::lock_guard<hierarchical_mutex> lk(low_level_mutex);  // 2) 线程当前锁级别大于　low_level_mutex，申请成功
	return do_low_level_stuff();
}

void high_level_stuff(int some_param)
{
	cout << __func__ << ":" << some_param <<endl;
}

void high_level_func()
{
	std::lock_guard<hierarchical_mutex> lk(high_level_mutex);   // １）　ULONG_MAX 大于任何锁级别，初始锁定正常,当前线程锁级别被更新为构造函数的锁级别
	high_level_stuff(low_level_func());
}

void thread_a()
{
	cout << __func__ << endl;
	high_level_func();
}

hierarchical_mutex other_mutex(100);
void do_other_stuff()
{
	cout <<__func__<<endl;
}

void other_stuff()
{
	cout << __func__<<endl;
	high_level_func();  // 申请大于当前线程锁级别的锁
	do_other_stuff();
}

void thread_b()
{
	cout << __func__ << endl;
	std::lock_guard<hierarchical_mutex> lk(other_mutex);  // 当前线程锁级别100
	other_stuff();
}

int main(int argc, char *argv[])
{
	thread ta(thread_a);
	ta.join();
	sleep(1);
	thread tb(thread_b);
	tb.join();
	return 0;
}

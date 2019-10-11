#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;


mutex producter_mut;
condition_variable data_producter_cont;
mutex consumer_mut;
condition_variable data_consumer_cont;
unsigned long int val;
unsigned long int old_val;

void thread_producter()
{
	
	while(1)
	{
		unique_lock<mutex> producter_lk(producter_mut);  // 并发数据保护
		val++;
		cout << "productor:" << val << endl;
		data_producter_cont.notify_one();
		producter_lk.unlock();


		unique_lock<mutex> consumer_lk(consumer_mut);   // 申请锁
		data_consumer_cont.wait(consumer_lk, [](){return old_val == val;}); // 等待
		consumer_lk.unlock(); // wait 返回时锁处于lock状态，所以需要unlock
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}


void thread_consumer()
{
	while(1)
	{
		unique_lock<mutex> producter_lk(producter_mut);
		data_producter_cont.wait(producter_lk, [](){return old_val < val;});
		cout << "consumer: " << val << endl;
		producter_lk.unlock();


		unique_lock<mutex> consumer_lk(consumer_mut);
		old_val = val;
		data_consumer_cont.notify_one();
		consumer_lk.unlock();
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

int main(int argc, char *argv[])
{

	thread tp(thread_producter);
	thread tc(thread_consumer);
	tc.join();
	tp.join();
	return 0;
}

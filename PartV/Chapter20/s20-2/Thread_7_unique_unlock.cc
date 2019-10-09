#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

mutex global_mutex;

void prepare_data()
{
	cout << "id " << this_thread::get_id()<<endl;
	cout << "1 " << __func__ << endl;
}

void do_some_thing()
{
	cout<<"2 "<<__func__<<endl;
}

void access_data()
{
	cout << "3 " << __func__ <<endl;
}

void process_data()
{
	unique_lock<mutex> lk(global_mutex);
	prepare_data();
	lk.unlock();
	do_some_thing();
	lk.lock();
	access_data();
}


void func()
{
	while(1)
	{
		process_data();
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	thread t1(func);
	thread t2(func);
	thread t3(func);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}

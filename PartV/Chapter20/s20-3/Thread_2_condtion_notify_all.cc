#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <unistd.h>

using namespace std;

mutex mut;
mutex all_mut;
condition_variable  notify_once_condition;
condition_variable  notify_all_condition;
int val;

void thread_notify_one()
{
	lock_guard<mutex> lk(mut);
	val = 1;
	notify_once_condition.notify_one();
	return;
}

void thread_wait_one()
{
	unique_lock<mutex> lk(mut);
	notify_once_condition.wait(lk, [](){return val == 1;});
	cout << "id:" << this_thread::get_id() << "have waited for one" << endl;
	lk.unlock();
	return;
}

void thread_notify_all()
{
	lock_guard<mutex> lk(all_mut);
	val = 2;
	notify_once_condition.notify_all();
	return;
}

void thread_wait_all()
{
	unique_lock<mutex> lk(all_mut);
	notify_once_condition.wait(lk, [](){return val == 2;});
	cout << "id:" << this_thread::get_id() << "have waited  for all" << endl;
	lk.unlock();
	return;
}
int main(int argc, char *argv[])
{
	thread tw1(thread_wait_one);
	thread tw2(thread_wait_one);
	thread tw3(thread_wait_one);
	sleep(1);
	thread tn(thread_notify_one);
	sleep(3);
	cout << "===========================================" << endl;

	thread taw1(thread_wait_all);
	thread taw2(thread_wait_all);
	thread taw3(thread_wait_all);
	sleep(1);
	thread tan(thread_notify_all);
	tw1.join();
	tw2.join();
	tw3.join();
	tn.join();
	taw1.join();
	taw2.join();
	taw3.join();
	tan.join();
	return 0;
}

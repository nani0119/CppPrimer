#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <future>

using namespace std;

void thread_calc(promise<int>& p)
{
	p.set_value(100);
	cout << __func__ << "exit" << endl;
}


void thread_wait_1(shared_future<int> sf)
{
	int a = sf.get();
	cout << __func__ << "   " << a << endl;
}
void thread_wait_2(shared_future<int> sf)
{
	int a = sf.get();
	cout << __func__ << "   " << a << endl;
}


int main(int argc, char *argv[])
{
	promise<int> p;
	// future<int> f = p.get_future();
	// shared_future<int> sf(std::move(f));

	shared_future<int> sf = p.get_future().share();
	thread tc(thread_calc, std::ref(p));
	thread t1(thread_wait_1, sf);
	thread t2(thread_wait_2, sf);
	tc.join();
	t1.join();
	t2.join();
	return 0;
}

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <unistd.h>

using namespace std;

class init_once
{
	private:
		int a = 0;
		once_flag init_flag;
		void open()
		{
			a++;
		}
	public:
		void init()
		{
			call_once(init_flag, &init_once::open, this);
		}
		int get_val()
		{
			return a;
		}
};

void thread_func(init_once& c)
{
	c.init();
	cout << c.get_val() << endl;
}

int main(int argc, char *argv[])
{
	init_once  v;
	thread t1(thread_func, std::ref(v));
	sleep(1);
	thread t2(thread_func, std::ref(v));
	t1.join();
	t2.join();
	return 0;
}

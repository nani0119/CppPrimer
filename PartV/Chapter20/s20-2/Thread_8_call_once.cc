#include <iostream>
#include <string>
#include <mutex>
#include <thread>

using namespace std;


once_flag init_flag;
int a;
void init_value()
{
	a++;
}


void foo()
{
	call_once(init_flag, init_value);
}


void bar()
{
	call_once(init_flag, init_value);
}


void thread_foo()
{
	foo();
	cout << a << endl;
}

void thread_bar()
{
	bar();
	cout << a << endl;
}

int main(int argc, char *argv[])
{
	thread tf(thread_foo);
	thread tb(thread_bar);

	tf.join();
	tb.join();
	return 0;
}

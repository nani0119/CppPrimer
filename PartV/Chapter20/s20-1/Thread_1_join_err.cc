#include <iostream>
#include <string>
#include <thread>

using namespace std;

//在函数内部创建线程，并且访问函数的本地变量，如果没有等待线程结束则存在问题

class func
{
public:
	int& i;
	func(int& i_): i(i_) {}

	void operator()()
	{
		for (int j = 0; j < 2000000; ++j) {
			do_something();
		}
		cout << endl;
	}
private:
	void do_something()
	{
		cout << ".";
	}
};

void oop()
{
	int local_state = 0;
	func my_func(local_state);
	thread my_thread(my_func);		     // my_thread线程访问了函数的临时变量，函数可能先于线程退出
	my_thread.detach();                  // error, do not wait thread finish
}


int main(int argc, char *argv[])
{
	return 0;
}

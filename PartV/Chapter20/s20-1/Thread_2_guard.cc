#include <iostream>
#include <string>
#include <thread>

using namespace std;

// 通过在线程保护类的析构函数增加join调用，保证线程在各种情况下(包括异常)，都能被等候

class func
{
public:
	int& i;
	func(int& i_): i(i_) {}

	void operator()()
	{
		for (int j = 0; j < 2; ++j) {
			do_something();
		}
		cout << endl;
	}
private:
	void do_something()
	{
		cout << __func__<<":"<< i <<endl;
	}
};


class thread_guard
{
private:
	thread& t;
public:
	explicit thread_guard(thread& t_): t(t_) {};
	thread_guard(const thread_guard&) = delete;
	thread_guard& operator=(const thread_guard&) = delete;
	~thread_guard()
	{
		if(t.joinable())
		{
			t.join();
		}
	}
};

void do_something_in_current_thread()
{
	cout << __func__ <<endl;
}

void f()
{
	int local_state = 0;
	func my_func(local_state);
	thread my_thread(my_func);
	thread_guard g(my_thread);          // t.join()在g的析构函数被执行时调用
	do_something_in_current_thread();
}
int main(int argc, char *argv[])
{
	f();
	return 0;
}

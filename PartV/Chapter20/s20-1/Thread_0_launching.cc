#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>


using namespace std;

// 适用函数或者可调用的对象构造线程

void do_some_work()
{
	cout << "Thread: do some work" <<endl;
}

class thread_obj   // 可调用对象
{
public:
	void operator()()
	{
		cout << "Thread: callable obj do some work" << endl;
	}
};


int main(int argc, char *argv[])
{
	// 使用函数 
	thread tf(do_some_work); 
	
	// 使用可调用的类
	// thread tc(thread_obj()); //　c++语法解析错误,compiler 认为tc是一个函数
	thread tc{thread_obj()};
	// thread tc((thread_obj()));
	
	// 使用lambda表达式
	thread tl([]()-> void {cout << "Thread: lambda expression" <<endl;});


	cout << "init thread finish" << endl;
	tf.join();
	tc.join(); // 等候线程结束
	tl.join();
	return 0;
}

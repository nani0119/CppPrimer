#include <iostream>
#include <string>
#include <thread>
#include <memory>
#include <unistd.h>

using namespace std;

// 线程使用的是值拷贝

void update(int& i,const string& s)
{
	cout <<i <<":" <<s << endl;
	i = 3;
}

void oop()
{
	char buffer[] = "abcdefg";
	int i = 0;
	// thread t(update, i, buffer);      // buffer需要转换为string,但是存在未转换完成前opp已经退出了.所以适用string(buffer)
	// thread t(update, i, string(buffer)); // 可调用对象的参数是值拷贝的，所以i的修改不会返回到opp中
	thread t(update, std::ref(i), string(buffer));
	t.detach();
	sleep(1);
	cout <<"update after: " << i << endl;
}


// 还有些情况不允许进行拷贝操作，比如unique_ptr, 这时需要适用std::move函数


void process_obj(unique_ptr<int> ui)
{
	*ui = 10;
	cout << *ui << endl;
}

void move_func()
{
	unique_ptr<int> pi(new int(5));
	thread t(process_obj, std::move(pi));
	t.detach();
	sleep(1);
	// cout << "update unique_ptr :" << *pi << endl;  // after std::move pi == nullptr
}


int main(int argc, char *argv[])
{
	oop();
	move_func();
	while(1);
	return 0;
}

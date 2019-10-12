#include <iostream>
#include <future>

using namespace std;

int  backgroud_do_something(int& i)
{
	cout << __func__ <<" id :"<< this_thread::get_id()<<endl;
	i++;
	return i;
}


int  async_backgroud_do_something(int& i)
{
	cout << __func__ <<" id :"<< this_thread::get_id()<<endl;
	i++;
	return i;
}


int  deferred_backgroud_do_something(int& i)
{
	cout << __func__ <<" id :"<< this_thread::get_id()<<endl;
	i++;
	return i;
}


int main(int argc, char *argv[])
{
	int i = 0;
	cout << "main thread id:" << this_thread::get_id()<< endl;
	future<int> answer = std::async(backgroud_do_something, std::ref(i));   // 默认适用std::lanch::async | std::launch::deferred启动选项，
																			//单独线程延期启动,在调用wait或者get时启动线程进行计算
	answer.wait();
	cout << "val:" << answer.get() << endl;


	cout << "=====================================================" << endl;
	i = 0;
	future<int> async_answer = std::async(std::launch::async, async_backgroud_do_something, std::ref(i));   //单独线程执行 run in a new thread
	cout << "val:" << async_answer.get() << endl;

	cout << "=====================================================" << endl;
	i = 0;
	future<int> deffed_answer = std::async(std::launch::deferred, deferred_backgroud_do_something, std::ref(i));   //延迟执行，不启动新线程执行
	cout << "val:" << deffed_answer.get() << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <thread>
#include <functional>
#include <algorithm>

using namespace std;

void do_work()
{
	cout << "do work:" << this_thread::get_id()  << endl;
}


void thread_func()
{
	vector<thread>  vec;
	auto cnt = thread::hardware_concurrency();
	if(cnt == 0)
	{
		cnt = 2;
	}
	else
	{
		cnt -= 1;
	}
	for (int i = 0; i < cnt; ++i) {
		vec.push_back(thread(do_work));
	}
	sleep(2);
	for_each(vec.begin(), vec.end(), mem_fn(&thread::join));

}

int main(int argc, char *argv[])
{
	thread_func();
	while(1);
	return 0;
}

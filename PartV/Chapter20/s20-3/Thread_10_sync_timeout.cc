#include <iostream>
#include <string>
#include <condition_variable>
#include <mutex>

using namespace std;


bool done;
condition_variable  cv;
mutex mux;


bool wait_loop()
{
	// converting from a time_t using the std::chrono::system_clock::to_time_point()
	//
	//
	//
	
	auto timeout = std::chrono::steady_clock::now() + std::chrono::milliseconds(2000);

	unique_lock<mutex> lk(mux);
	while(!done)  // 不带谓语的同步超时等待时可能出现假唤醒情况,所以使用while测试
	{
		if(cv.wait_until(lk,timeout) == std::cv_status::timeout)    //注意与使用wait_for区别，如果使用wait_for，当出现
																	//假唤醒时，等候的时间会超出你期望的时间
		{
			cout << "time out" << endl;
		}
		break;
	}
	return done;
}


int main(int argc, char *argv[])
{
	wait_loop();
	return 0;
}

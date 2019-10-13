#include <iostream>
#include <string>
#include <future>


using namespace std;


void do_some_thing()
{
	this_thread::sleep_for(std::chrono::milliseconds(3000));
}



int main(int argc, char *argv[])
{
	future<void> f = async(do_some_thing);
	if(f.wait_for(std::chrono::milliseconds(2000)) == std::future_status::timeout)
	{
		cout << "time out" << endl;
	}
	return 0;
}

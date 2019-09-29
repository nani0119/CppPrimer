#include <iostream>
#include <string>
#include <thread>
#include <exception>
#include <unistd.h>


using namespace std;


class func{

	public:
		void operator()(int& i)
		{
			cout << "update data" << endl;
			i++;
		}
};

class scoped_thread
{
	private:
		thread t;
	public:
		explicit scoped_thread(thread t_): t(std::move(t_)) 
		{
			if(!t.joinable())
			{
				throw logic_error("No thread");
			}
		}
		scoped_thread(const scoped_thread&) = delete;
		scoped_thread& operator=(const scoped_thread&) = delete;
		~scoped_thread()
		{
			t.join();
		}
};

void thread_func()
{
	int i = 0;
	scoped_thread t(thread(func(), std::ref(i)));
	sleep(1);
	cout << i << endl;
}


int main(int argc, char *argv[])
{
	thread_func();
	return 0;
}

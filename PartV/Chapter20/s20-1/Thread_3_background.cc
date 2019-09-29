#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>

using namespace std;

class background_func
{
	public:
		void operator()()
		{
			int i = 0;
			while(1){
				cout << __func__ <<i++<<endl;
			}
		}
};


class thread_guard
{
	private:
		thread& t;
	public:
		explicit thread_guard(thread& t_) : t(t_) {}
		thread_guard(const thread_guard&) = delete;
		thread_guard& operator=(const thread_guard&) = delete;
		~thread_guard()
		{
			if(t.joinable())
			{
				cout << "thread detach" << endl;
				t.detach();
			}
		}
};

void background()
{
	background_func bf;
	thread bt(bf);
	thread_guard g(bt);
}

int main(int argc, char *argv[])
{
	background();
	while(1);
	return 0;
}

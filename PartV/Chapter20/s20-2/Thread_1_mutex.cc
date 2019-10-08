#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <exception>


using namespace std;


class data
{
private:
	int a = 0;
	mutex m;
public:
	void show_data()
	{
		lock_guard<mutex> g(m);
		cout << "value:" << a << endl;
	}
	void process_data()
	{
		lock_guard<mutex> g(m);
		a++;
	}
};

class thread_guard
{
private:
	thread t;
public:
	explicit thread_guard(thread t_): t(std::move(t_))
	{
		if (!t.joinable())
			throw logic_error("not thread");
	}
	~thread_guard()
	{
		t.join();
	}
	thread_guard(const thread_guard&) = delete;
	void operator=(const thread_guard&) = delete;
};

void func(data& d)
{
	d.process_data();
	d.show_data();
}
int main(int argc, char *argv[])
{
	data d;
	thread_guard t1 (thread(func,std::ref(d)));
	thread_guard t2 (thread(func,std::ref(d)));
	thread_guard t3 (thread(func,std::ref(d)));
	return 0;
}

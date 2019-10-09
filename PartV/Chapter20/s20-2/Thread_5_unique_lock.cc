#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <exception>
#include <unistd.h>

using namespace std;

class some_obj
{
	private:
		int data = 0;
	public:
		some_obj() = default;
		some_obj(int i): data(i) {}
		some_obj(const some_obj& obj)
		{
			data = obj.data;
		}
		void show_data()
		{
			cout << data << endl;
		}
};

class X
{
	private:
		some_obj some_detail;
		mutex m;
	public:
		X(const some_obj& obj): some_detail(obj) {}

		some_obj& get_data()
		{
			return some_detail;
		}
		friend void swap(X& lhs, X& rhs)
		{
			if(&lhs == &rhs)
				return;
			unique_lock<mutex> lock_a(lhs.m, std::defer_lock);  // 延迟锁
			unique_lock<mutex> lock_b(rhs.m, std::defer_lock);
			lock(lhs.m, rhs.m);
			// lock_guard<mutex> lock_a(lhs.m, std::adopt_lock);
			// lock_guard<mutex> lock_b(rhs.m, std::adopt_lock);
			std::swap(lhs.some_detail, rhs.some_detail);
		}
};

void swap(X& lhs, X& rhs);
class thread_guard
{
	private:
		thread t;
	public:
		thread_guard(thread t_): t(std::move(t_))
		{
			if(!t.joinable())
				throw logic_error("No thread");
		}
		thread_guard(const thread_guard&) = delete;
		thread_guard& operator=(const thread_guard&) = delete;
		~thread_guard()
		{
			t.join();
		}
};

void func(X& lhs, X& rhs)
{
	::swap(std::ref(lhs), std::ref(rhs));
}
int main(int argc, char *argv[])
{
	X lhs(some_obj(1));
	X rhs(some_obj(2));
	lhs.get_data().show_data();
	cout << endl;
	rhs.get_data().show_data();
	// thread_guard t(thread(::swap, std::ref(lhs), std::ref(rhs)));
	thread_guard t(thread(func, std::ref(lhs), std::ref(rhs)));
	thread_guard t1(thread(func, std::ref(lhs), std::ref(rhs)));
	thread_guard t2(thread(func, std::ref(lhs), std::ref(rhs)));
	sleep(1);
	lhs.get_data().show_data();
	cout << endl;
	rhs.get_data().show_data();

	return 0;
}

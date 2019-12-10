#include "concurrent.h"
#include <string>
using namespace std;

class spinlock_mutex spinlock;
void spinlock_test_inner()
{
	spinlock.lock();
	cout << __func__<<" uses spinlock"<<endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	spinlock.unlock();
}


void add_item_2_stack(threadsafe_stack<int>& stack)
{
	for(int i = 0, item = i; i < 100; i++, item = i)
	{
		stack.push(item);
	}
}

void remove_item_from_stack1(threadsafe_stack<int>& stack)
{
	int i;
	try
	{
		while(1)
		{
			stack.pop(i);
			cout << __func__ << ":" << i << endl;
		}

	} 
	catch(empty_stack e)
	{
			cout << __func__<<":"<<e.what() << endl;
	}
}

void remove_item_from_stack2(threadsafe_stack<int>& stack)
{
	shared_ptr<int> pi;
	try
	{
		while(1)
		{
			pi = stack.pop();
			cout << __func__ << ":" << *pi << endl;
		}
	} 
	catch(empty_stack e)
	{
		cout << __func__<<":"<<e.what() << endl;
	}
}
void threadsafe_stack_test()
{
	threadsafe_stack<int> stk;
	thread_guard tadd1(thread{add_item_2_stack, std::ref(stk)});
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	thread_guard trm1(thread{remove_item_from_stack1, std::ref(stk)});
	thread_guard tadd2(thread{add_item_2_stack, std::ref(stk)});
	thread_guard trm2(thread{remove_item_from_stack2, std::ref(stk)});
}

void add_item_2_queue(threadsafe_queue<int>& q)
{
	for(int i = 0, item = i; i < 100; i++,item = i)
	{
		q.push(item);
	}
}

void remove_item_from_queue1(threadsafe_queue<int>& q)
{
	shared_ptr<int> pq;
	while(!q.empty())
	{
		pq = q.wait_and_pop();
		if(pq)
		{
			cout << __func__<<":" << *pq << endl;
		}
	};
}

void remove_item_from_queue2(threadsafe_queue<int>& q)
{
	bool ret = true;
	int i = 0;
	while(!q.empty())
	{
		ret = q.try_pop(i);
		if(ret)
		{
			cout << __func__<<":" << i << endl;
		}
	}
}

void threadsafe_queue_test()
{
	threadsafe_queue<int> q;
	thread_guard ta(thread{add_item_2_queue, std::ref(q)});
	thread_guard tr1(thread{remove_item_from_queue1, std::ref(q)});
	thread_guard tr2(thread{remove_item_from_queue2, std::ref(q)});
}
void spinlock_test()
{
	thread_guard spinlock_test1(thread{spinlock_test_inner});
	thread_guard spinlock_test2(thread{spinlock_test_inner});
	thread_guard spinlock_test3(thread{spinlock_test_inner});
}

string task1()
{
	return  __func__;
}
string task2()
{
	return  __func__;
}

void thread_pool_test()
{
	thread_pool pool;
	int i = 0;
	while(1)
	{
		if(i%2 == 0)
		{
			future<string> f =  pool.submit(task1);
			cout << "it is " << f.get()<<endl;
		}
		else
		{
			future<string> f =  pool.submit(task2);
			cout << "it is " << f.get()<<endl;
		}
		i++;
		// std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

condition_variable cv;
mutex mut;
unique_lock<mutex> lk(mut);

void f()
{
	cout <<"i sleep" << endl;
	interruptible_wait(cv, lk, [](){volatile bool b = false; return b;});
	cout <<"i am wake up" << endl;
}
void interruptible_thread_test()
{
	interruptible_thread t (f);
	this_thread::sleep_for(std::chrono::milliseconds(5000));
	t.interrupt();
	t.join();
}

int main(int argc, char *argv[])
{
	threadsafe_stack_test();
	threadsafe_queue_test();
	spinlock_test();
    interruptible_thread_test();
	thread_pool_test();

	return 0;
}

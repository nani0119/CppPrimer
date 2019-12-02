#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#include <memory>
#include <exception>
#include <cstddef>

using namespace std;

template<typename T>
class lock_free_stack{

	struct node{
		shared_ptr<T> data;
		node* next;

		node(T const& data_): data(make_shared<T>(data_))
		{

		}
	};
	
	atomic<node*> head;
	atomic<int> cnt;
public:
	lock_free_stack(): head(NULL){}
	lock_free_stack(lock_free_stack&) = delete;
	lock_free_stack& operator=(lock_free_stack&) = delete;
	void push(T const& data)
	{
		node* const new_node = new node(data);
		new_node->next = head.load();
		while(!head.compare_exchange_weak(new_node->next, new_node))
		{}
		cnt.fetch_add(1);
	}

	shared_ptr<T> pop()
	{
		node* old_head = head.load();
		while(old_head && !head.compare_exchange_weak(old_head, old_head->next))
		{}
		return old_head?(cnt.fetch_sub(1),old_head->data):shared_ptr<T>();
	}


	int size()
	{
		return cnt.load();
	}


};

class thread_guard
{
	thread t;
public:

	explicit thread_guard(thread t_) : t(std::move(t_))
	{
		if(!t.joinable())
		{
			throw std::logic_error("no thread");
		}
	}
	~thread_guard()
	{
		t.join();
	}

	thread_guard() = delete;
	thread_guard& operator=(thread_guard&) = delete;

};

atomic<int> msg(0);

void report_size(lock_free_stack<int>& stack)
{
	while(1)
	{
		cout << "stack size:" << stack.size() << endl;
		this_thread::sleep_for(std::chrono::milliseconds(9999));
	}
}

void producter(lock_free_stack<int>& stack)
{
	while(1)
	{
		stack.push(msg);
		msg.fetch_add(1);
		this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void consumer(lock_free_stack<int>& stack)
{
	shared_ptr<int> i = NULL;
	while(1)
	{
		i = stack.pop();
		if(i != NULL)
		{
			cout << this_thread::get_id() << " " << *i << endl;
			this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
}

int main(int argc, char *argv[])
{
	lock_free_stack<int> stack;
	thread_guard tpush(thread(producter, std::ref(stack)));
	thread_guard tpop(thread(consumer, std::ref(stack)));
	thread_guard tpop1(thread(consumer, std::ref(stack)));
	thread_guard tpush1(thread(producter, std::ref(stack)));
	thread_guard report(thread(report_size, std::ref(stack)));
	return 0;
}

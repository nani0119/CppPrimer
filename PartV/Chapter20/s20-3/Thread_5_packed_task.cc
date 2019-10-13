#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

template <typename T>
class threadsafe_queue
{
	private:
		mutable mutex mut;
		condition_variable data_cont;
		deque<T> data_queue;
	public:
		threadsafe_queue(){}
		threadsafe_queue(threadsafe_queue& other)
		{
			lock_guard<mutex> lk(other.mut);
			data_queue = other.mut;
		}

		void push(T&& value)
		{
			lock_guard<mutex> lk(mut);
			data_queue.push_back(std::move(value));
			data_cont.notify_one();
		}

		void push(T& value)
		{
			lock_guard<mutex> lk(mut);
			data_queue.push_back(std::move(value));
			data_cont.notify_one();
		}
		void wait_and_pop(T& value)
		{
			unique_lock<mutex> lk(mut);
			data_cont.wait(lk, [this](){return !data_queue.empty();});
			value = std::move(data_queue.front());
			data_queue.pop_front();
			return ;
		}

		shared_ptr<T> wait_and_pop()
		{
			unique_lock<mutex> lk(mut);
			data_cont.wait(lk, [this](){return !data_queue.empty();});
			shared_ptr<T> res (make_shared<T>(std::move(data_queue.front())));
			data_queue.pop_front();
			return res;
		}
		bool empty() const
		{
			lock_guard<mutex> lk(mut);
			return data_queue.empty();
		}

		unsigned int size() const
		{
			lock_guard<mutex> lk(mut);
			return data_queue.size();
		}
};


bool draw_square(int i)
{
	cout << __func__  << " : "<< i << endl;
	return true;
}

bool draw_circle(int i)
{
	cout << __func__  << " : "<< i << endl;
	return true; 
}

void thread_gui_square(threadsafe_queue<packaged_task<bool(int)>>& q)
{
	while(1)
	{
		packaged_task<bool(int)> square_task(draw_square);
		q.push(std::move(square_task));
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}

}


void thread_gui_circle(threadsafe_queue<packaged_task<bool(int)>>& q)
{
	while(1)
	{
		packaged_task<bool(int)> circle_task(draw_circle);
		q.push(circle_task);
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}

}

future<bool> gui_process_event_one(threadsafe_queue<packaged_task<bool(int)>>& q, int i)
{
	packaged_task<bool(int)> task;
	q.wait_and_pop(task);
	future<bool> ret = task.get_future();
//	task(i);
	return ret;
}


future<bool> gui_process_event_two(threadsafe_queue<packaged_task<bool(int)>>& q, int i)
{
	auto ptask = q.wait_and_pop();
	future<bool> ret = ptask->get_future();
	(*ptask)(i);
	return ret;
}

void thread_gui_process_event(threadsafe_queue<packaged_task<bool(int)>>& q)
{
	int i = 0;
	while(1)
	{
		future<bool> ret;
		if(i%2 != 0)
		{
			ret = gui_process_event_one(q,i);
		}
		else
		{
			ret = gui_process_event_two(q,i);
		}
		if(ret.get())
		{
			cout << "task has been procecssed" << endl;
			i++;
		}
	}
}
int main(int argc, char *argv[])
{
	threadsafe_queue<packaged_task<bool(int)>> event_queue;

	thread thread_revice(thread_gui_process_event, std::ref(event_queue));
	thread thread_send_circle(thread_gui_circle, std::ref(event_queue));
	thread thread_send_square(thread_gui_square, std::ref(event_queue));

	thread_revice.join();
	thread_send_circle.join();
	thread_send_square.join();
	return 0;
}

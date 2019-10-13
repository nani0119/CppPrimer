#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <mutex>
#include <deque>
#include <map>
using namespace std;

struct payload
{
	int id;
	int data;
	payload(int i, int j) : id(i), data(j){}
};

class incoming_data
{
	private:
		mutex data_mux;
		mutex map_mux;
		deque<payload> data_queue;
		map<int, promise<payload>> promise_map;
	public:
	incoming_data() = default;
	incoming_data(const incoming_data&) = delete;
	incoming_data& operator=(const incoming_data&) =delete;
	void register_promise(int id, promise<payload>& p)
	{
		lock_guard<mutex> lk(map_mux);
		promise_map.insert({id,std::move(p)});
	}
	bool commit_data()
	{
		lock(map_mux,data_mux);
		lock_guard<mutex> lkm(map_mux,std::adopt_lock);
		lock_guard<mutex> lkd(data_mux,std::adopt_lock);
	
		if(data_queue.empty() || promise_map.empty())
		{
			return false;
		}	

		payload item = data_queue.front();
		auto it = promise_map.find(item.id);
		if(it == promise_map.end())
		{
			data_queue.pop_front();
			add_data(item);
			return false;
		}
		else
		{
			promise<payload> p = std::move(it->second);
			p.set_value(item);
			promise_map.erase(item.id);
			data_queue.pop_front();
			return true;
		}
	}
	
	void add_data(payload& data)
	{
		lock_guard<mutex> lk(data_mux);
		data_queue.push_back(data);
	}
};

void thread_promise_a(incoming_data& d)
{
	while(1)
	{
		promise<payload> p;
		future<payload> f = p.get_future();
		d.register_promise(0, p);
		payload data = f.get();
		cout << "id " << data.id << "  " << " value" << data.data << endl;
	}
	
}


void thread_promise_b(incoming_data& d)
{
	while(1)
	{
		promise<payload> p;
		future<payload> f = p.get_future();
		d.register_promise(1, p);
		payload data = f.get();
		cout << "id " << data.id << "  " << " value" << data.data << endl;
	}
	
}

void thread_promise_c(incoming_data& d)
{
	while(1)
	{
		promise<payload> p;
		future<payload> f = p.get_future();
		d.register_promise(2, p);
		payload data = f.get();
		cout << "id " << data.id << "  " << " value" << data.data << endl;
	}
	
}

void thread_productor(incoming_data& d)
{
	int i = 0;
	while(1)
	{
		cout << "product " << i%3  << " " << i << endl;
		payload data(i%3, i);
		d.add_data(data);
		this_thread::sleep_for(std::chrono::milliseconds(500));
		i++;
	}
}

int main(int argc, char *argv[])
{
	incoming_data  data;

	thread tp1(thread_promise_a, std::ref(data));
	thread tp2(thread_promise_b, std::ref(data));
	thread tp3(thread_promise_c, std::ref(data));
	thread td(thread_productor, std::ref(data));
	while(1)
	{
		data.commit_data();
		this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	tp1.join();
	tp2.join();
	tp3.join();
	td.join();

	return 0;
}

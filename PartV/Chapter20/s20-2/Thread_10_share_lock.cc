#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <random>
#include <ctime>
#include <unistd.h>

using namespace std;

class dns_entry
{
	private:
		string ip;
	public:
		dns_entry(const string& v):ip(v) {}
		dns_entry() = default;
		void set(const string& val)
		{
			ip = val;
			return;
		}
		string get()
		{
			return ip;
		}
};

class dns_cache
{
	private:
		map<string, dns_entry> entries;
		mutable shared_mutex entry_mutex;
	public:
		dns_entry find_entry(const string& domain)
		{
			shared_lock<shared_mutex> lk(entry_mutex);
			auto it = entries.find(domain);
			if(it == entries.end())
				return dns_entry();
			else
				return it->second;
		}

		void update_and_add_entry(const string& domain, const dns_entry& dns_detail)
		{
			lock_guard<shared_mutex> lk(entry_mutex);
			entries.insert(make_pair(domain, dns_detail));
		}
};

int random_domain()
{
	static default_random_engine e(time(0));
	static uniform_int_distribution<int> u(0,9);
	return u(e);
}

void thread_reader(dns_cache& cache)
{
	string domain;
	while(1)
	{
		domain = to_string(random_domain());
		auto entry = cache.find_entry(domain);
		string ip = entry.get().size() == 0? "NULL":entry.get();
		cout << "domain: " << domain << " : ip :"<< ip  << endl;
		sleep(random_domain());
	}
}

void thread_updater(dns_cache& cache)
{

	string domain;
	dns_entry detail;
	while(1)
	{
		domain = to_string(random_domain());
		detail.set(to_string(random_domain()));
		cache.update_and_add_entry(domain,detail);
		sleep(2);
	}
}

int main(int argc, char *argv[])
{
	dns_cache cache;
	thread tu(thread_updater,std::ref(cache));
	thread tr1(thread_reader, std::ref(cache));	
	thread tr2(thread_reader, std::ref(cache));	
	thread tr3(thread_reader, std::ref(cache));	
	thread tr4(thread_reader, std::ref(cache));	
	thread tr5(thread_reader, std::ref(cache));	

	tu.join();
	tr1.join();
	tr2.join();
	tr3.join();
	tr4.join();
	tr5.join();
	return 0;
}


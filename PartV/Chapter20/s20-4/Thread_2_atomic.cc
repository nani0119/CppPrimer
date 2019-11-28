#include <iostream>
#include <vector>
#include <atomic>
#include <thread>
#include <cassert>

using namespace std;

atomic<int> atomic_cnt = {0};
int cnt = 0;


void atomic_f()
{
	for (int i = 0; i < 1000; ++i) {
		atomic_cnt.fetch_add(1,std::memory_order::memory_order_relaxed);
	}
}

void f()
{
	for (int i = 0; i < 1000; ++i) {
		cnt += 1;
	}
}


int main(int argc, char *argv[])
{
	vector<thread> va;
	vector<thread> vf;

	for (int i = 0; i < 10; ++i) {
		va.emplace_back(atomic_f);
	}

	for (auto& t : va) {
		t.join();
	}
	cout << atomic_cnt << endl;
	assert(atomic_cnt==10000);
	for (int i = 0; i < 10; ++i) {
		vf.emplace_back(f);
	}

	for (auto& t : vf) {
		t.join();
	}
	cout << cnt << endl;
	assert(cnt == 10000);
	return 0;
}

#include <iostream>
#include <atomic>
#include <thread>
#include <cassert>
using namespace std;


// acquire-release原子原语不能保证线程的先后执行关系,保证load-acquire成立时，store-release前的写完成，其他线程能看到真实值
atomic<bool> ready{false};
int data = 0;

atomic<bool> ready_next{false};
int data_next = 0;


void product()
{
	data = 100;
	ready.store(true, std::memory_order::memory_order_release);  // 保证写操作完成，写入内存，同步cache，其他线程看到相同的结果
}

void consumer()
{
	// ready 为true时，　ready　store-release 前的写操作完成，当前线程可以看到
	while(!ready.load(std::memory_order::memory_order_acquire))
	{}

	cout << data << endl;
	assert(data == 100);
	data_next = 200;
	ready_next.store(true, std::memory_order::memory_order_release);   // 保证写操作完成，写入内存，同步cache，其他线程看到相同的结果
}

void consumer_next()
{
	// ready_next为true时，　ready_next　store-release 前的写操作完成，当前线程可以看到
	while(!ready_next.load(std::memory_order::memory_order_acquire))
	{}

	cout << data_next << endl;
	assert(data_next == 200);
}


int main(int argc, char *argv[])
{
	thread tc1(consumer_next);
	thread tp(product);
	thread tc(consumer);

	tc1.join();
	tp.join();
	tc.join();
	return 0;
}

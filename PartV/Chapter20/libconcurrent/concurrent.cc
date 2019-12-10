#include "concurrent.h"
// ================== thread_guard begin =============================
thread_guard::thread_guard(std::thread t_): t(std::move(t_))
{
	if(!t.joinable())
	{
		throw std::logic_error("No thread");
	}
}

thread_guard::~thread_guard()
{
	t.join();
}

// ================== thread_guard end  =============================



// =================== spinlock_muxtex begin ===========================
		
spinlock_mutex::spinlock_mutex(): flag(ATOMIC_FLAG_INIT)
{}

void spinlock_mutex::lock()
{
	while(flag.test_and_set(std::memory_order_acquire));
}

void spinlock_mutex::unlock()
{
	flag.clear(std::memory_order_release);
}

// =================== spinlock_muxtex end ===========================


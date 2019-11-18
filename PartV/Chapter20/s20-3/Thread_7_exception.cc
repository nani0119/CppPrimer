#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <mutex>
#include <condition_variable>

using namespace std;

void async_throw_exception()
{
	throw logic_error("async throw exception");
}

void packaged_task_throw_exception()
{
	throw logic_error("packaged task throw exception");
}

void do_something()
{
	cout << __func__ << endl;
}

void promise_throw_exception(promise<int>& p)
{
	p.set_exception(make_exception_ptr(logic_error("promise throw exception")));
	do_something();
}

void promise_throw_exception_untile_return(promise<int>& p)
{
	p.set_exception_at_thread_exit(make_exception_ptr(logic_error("promise throw exception")));
	do_something();
}
int main(int argc, char *argv[])
{
	future<void> async_ret = async(async_throw_exception);
	try{
		async_ret.get();
	}
	catch(logic_error e)
	{
		cout << e.what() << endl;
	}

	//===============================================================
	future<void> task_ret;
	{
		packaged_task<void()> task(packaged_task_throw_exception);
		task_ret = task.get_future();
	}  //  packaged_task class destory
	try
	{
		task_ret.get();
	}
	catch (logic_error e)
	{
		cout << e.what() << endl;
	}	


	packaged_task<void()> task1(packaged_task_throw_exception);
	task1();
	future<void> task1_ret = task1.get_future();
	try
	{
		task1_ret.get();
	}
	catch (logic_error e)
	{
		cout << e.what() << endl;
	}	

	//===============================================================
	
	promise<int> pm;
	future<int> pm_ret = pm.get_future();
	thread tpm(promise_throw_exception, std::ref(pm));
	tpm.join();
	try
	{
		pm_ret.get();
	}
	catch (logic_error e)
	{
		cout << e.what() << endl;
	}
	
	future<int> pm_ret1;
	{
		promise<int> pm1;
		pm_ret1 = pm1.get_future();
	}

	try
	{
		pm_ret1.get();
	}
	catch (logic_error e)
	{
		cout << e.what() << endl;
	}
	cout << "================="	 << endl;
	promise<int> pm2;
	future<int> pm_ret2 = pm2.get_future();
	thread tpm2(promise_throw_exception_untile_return, std::ref(pm2));
	tpm2.join();
	try
	{
		pm_ret2.get();
	}
	catch (logic_error e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

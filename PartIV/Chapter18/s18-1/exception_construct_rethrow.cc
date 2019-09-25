#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <exception>
#include <stdexcept>

using namespace std;


class E {
private:
	int a = 0;
public:
	E(int num) try : a(num)    //function try
   	{ 
		try
		{
			std::exception e;
			throw e;
		}
		catch (std::exception e)
		{
			cout << "E inside construct exception" << endl;
		}
		cout << "E construct"<<endl; 
	}
	catch(...)
	{
		cout << "E construct exception" << endl;
	}
	~E() {cout << "~E deconstruct" << endl;}
	void not_throw() noexcept
	{
		cout << "a:" << a << endl;
	}
	void throw_exception_outside()
	{
		try {
			cout << "throw_exception_outside begin" << endl;
			not_throw();
			throw_exception();
			cout << "throw_exception_outside end" << endl;
		}
		catch (...)
		{
			cout << "throw_exception_outside exception"<< endl;
		}
	}
	void throw_exception() 
	{ 
		try
		{
			runtime_error error("throw runtime_error exception");
			exception* e = &error;
			throw e;
			// runtime_error error("throw runtime_error exception");
			// runtime_error & e = error;
			// throw e;
			cout << "not exec" << endl;
		}
		catch (exception*  err)
		// catch(exception & err)
		{
			cout << "err->what:"<< err->what() << endl;
			// cout << "err.what:" << err.what()<<endl;
			throw;   //rethrow
		}
		cout << "throw_exception finish" << endl;
	}

};

int main(int argc, char* argv[])
{
	E e(1);
	e.throw_exception_outside();
	return 0;
}

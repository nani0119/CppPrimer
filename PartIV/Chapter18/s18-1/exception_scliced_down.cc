#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <exception>
#include <stdexcept>

using namespace std;

void func()
{
	range_error r("error");
	exception* p = &r;
	try
	{
		// throw r;
		throw *p;  //scliced down
	}
	catch (range_error e)
	{
		cout << "range_error:" <<e.what()<< endl;
	}
	catch (exception e)
	{
		cout << "exception error:" <<e.what()<< endl;
	}

}

void func1()
{
	range_error r("range error:pointer");
	exception* p = &r;

	try
	{
		throw p;    // pointer ,scliced down

	}
	catch (range_error* e)
	{
		cout << "range_error:" <<e->what()<< endl;
	}
	catch (exception* e)
	{
		cout << "exception error:" <<e->what() <<endl;
	}
}

void func2()
{
	range_error r("range error:reference");
	exception& p = r;

	try
	{
		throw p;    // pointer ,scliced down

	}
	catch (range_error& e)
	{
		cout << "range_error:" <<e.what() <<endl;
	}
	catch (exception& e)
	{
		cout << "exception error:" << e.what()<<endl;
	}
}


int main(int argc, char* argv[])
{
	func();
	func1();
	func2();
	return 0;
}

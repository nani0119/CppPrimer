#include <iostream>
#include <string>
#include <exception>

using namespace std;

void throw_exception()
{
	throw runtime_error("runtime error");
}

int main(int argc, char *argv[])
{
	try{
		throw_exception();
		cout << "not exec" << endl;
	}
	catch(runtime_error err){
		cout << err.what() << endl;	
	}
	catch(...)
	{
		cout << "catch any exception" << endl;
	}
	cout << "finish" << endl;
	return 0;
}

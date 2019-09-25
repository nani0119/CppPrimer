#include <iostream>
#include <exception>

using namespace std;

void do_throw() 
{
	exception e;
	throw e;
}

void not_throw() noexcept
{
}	


int main(int argc, char *argv[])
{
	cout << boolalpha;
		cout << "do_throw:" << noexcept(do_throw()) << endl;
		cout << "not_throw:"<< noexcept(not_throw()) << endl;
	cout <<noboolalpha;
	return 0;
}

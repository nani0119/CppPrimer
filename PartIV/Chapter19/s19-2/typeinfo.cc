#include <iostream>
#include <typeinfo>
#include <string>


using namespace std;

class Sales_data
{
};

class Base{
};

class Derived :public Base
{
};


int main(int argc, char *argv[])
{
	int arr[10];
	Derived d;
	Base *p = &d;
	cout <<"typeid(42).name(): " << typeid(42).name() << endl
		<<"typeid(arr).name(): " <<typeid(arr).name() << endl
		<< "typeid(Sales_data).name(): "<<typeid(Sales_data).name() << endl
		<< "typeid(std::string).name(): "<< typeid(std::string).name() << endl
		<<"typeid(p).name(): " <<typeid(p).name() << endl
		<<"typeid(*p).name(): "<<typeid(*p).name() << endl;
	return 0;
}

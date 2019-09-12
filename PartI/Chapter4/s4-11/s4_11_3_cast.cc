#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
	virtual void print()
	{
		cout << "I am class Base" << endl;
	}
};

class Derived : public Base
{
public:
	void print()
	{
		cout << "I am class Derived" << endl;
	}

	void show()
	{
		cout << "show show" << endl;
	}
};


int main(int argc, char *argv[])
{
	double pi = 3.13;
	void* vppi = &pi;
	double* ppi = static_cast<double*>(vppi);
	int i = static_cast<int>(pi);

	cout << i << " " << *ppi <<endl;
	cout <<"============================================" << endl;

	// A const_cast changes only a low-level const in its operand
	const char* pc;
	char*  p = const_cast<char*>(pc);  // ok: but writing through p is undefined

	cout << "===========================================" << endl;
	// 强制类型转换
	int* ip;
	char* cp = reinterpret_cast<char*>(ip);
	cout << "===========================================" << endl;

	// The dynamic_cast operator, which safely converts a pointer or reference to a
    // base type into a pointer or reference to a derived type
	
	Base b;
	Derived d;

	Base* bp = &b;

	if(Derived* dp = dynamic_cast<Derived*>(bp))
	{
		dp->print();
		dp->show();
	}
	else
	{
		bp->print();
	}

    //===========================================================	
   
	bp = &d;

	if(Derived* dp = dynamic_cast<Derived*>(bp))
	{
		dp->print();
		dp->show();
	}
	else
	{
		bp->print();
	}
	
	return 0;
}

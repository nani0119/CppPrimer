#include <iostream>
#include <string>

using namespace std;

//========================================================================

void change_value(int* pi)
{
	(*pi)++;
}

void change_value(int& ri)
{
	++ri;
}

//=========================================================================

// top-level const is ignore,so passing const or plain is the same. 
// redefine void func(int i)
void fnc(const int i)   
{
	cout << "top-level const"<< i << endl;
}

// void fnc(int i)
// {
// 	cout << i << endl;
// }
//==========================================================================

void bar(const int* pi)
{
	cout << "low-level const int* " <<*pi<< endl;
}

void bar(int* pi)
{
	cout << "plain int* " << *pi << endl;
}

// redefine with void bar(const int* pi)
// void bar(const int a[])
// {
	// cout << "const int a[]" << endl;
// }


// redefine with void bar(const int* pi)
// void bar(const int a[10])
// {}
//===========================================================================

// reference is always low-level,so can not be ignore
void foo(const int& i)
{
	cout << "const int& " << i <<endl;
}

void foo(int& i)
{
	cout << "plain int& " << i << endl;
}

//=========================================================================

// Array Reference Parameters

void print(int (&arry)[3])
{
	for(auto it: arry)
		cout << it << "  ";
	cout << endl;
}

//=========================================================================
int main(int argc, char *argv[])
{
	int i = 0;
	const int j = 0;
	cout << i << endl;
	change_value(&i);
	cout << i << endl;
	change_value(i);
	cout << i << endl;

	fnc(i);

	foo(i);
	foo(j);


	bar(&i);
	bar(&j);

	int a[3] = {1,2,3};
	print(a);
	return 0;
}

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;


template <typename T> 
void f1(T&) 	// argument must be an lvalue
{
	cout <<__func__<<":"<< typeid(T).name() << endl;
}


template <typename T> 
void f2(const T&) 	// argument must be an lvalue
{
	cout <<__func__<<":"<< typeid(T).name() << endl;
}


template <typename T>
//  X& &, X& &&, and X&& & all collapse to type X&
//  the type X&& && collapses to X&&
void f3(T&& val)
{

	cout <<__func__<<":"<< typeid(T).name() << endl;
	T t = val; // copy or binding a reference?
	if (val == t) { /* ... */ }

	// literal 42, T is int, => int t = val
	// lvalue i,   T is int&  => int& t = val.
	// The initialization of t binds t to val. When we assign to t, we change val at the same time. In this
    // instantiation of f3, the if test will always yield true.
}

// so,
// template <typename T> void f(T&&); // binds to nonconst rvalues
// template <typename T> void f(const T&); // lvalues and const rvalues


int main(int argc, char *argv[])
{
	int i = 1;
	const int ci = 1;
	string s = "aaaa";


	f1(i);      // T is int
	f1(ci);     // T is const int
	f1(s);      // T is string
	// f1(5);      // error: argument to a & parameter must be an lvalue
	

	// notice
	// use const
	f2(i);      // T is int
	f2(ci);     // T is const int
	f2(s);      // T is string
	f2(5);      // a const & parameter can be bound to an rvalue; T is int


	// use &&
	f3(i);      // T is int
	f3(ci);     // T is const int
	f3(s);      // T is string
	f3(5);      // a const & parameter can be bound to an rvalue; T is int
	return 0;
}

#include <iostream>
#include <string>


using namespace std;

//  X& &, X& &&, and X&& & all collapse to type X&
//  the type X&& && collapses to X&&
template <typename F, typename T1, typename T2>
void Flip1(F f, T1 t1, T2 t2)
{
	f(t1, t2);
}


template <typename F, typename T1, typename T2>
void Flip2(F f, T1 &&t1, T2 &&t2)
{
	f(t1, t2);
}

template <typename F, typename T1, typename T2>
void Flip(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T1>(t1), std::forward<T2>(t2));
}

void f(int& v1, int v2) // v2 is a reference
{
	cout << v1 << " " << ++v2 << endl;
}


// This version of flip2 solves one half of our problem. Our flip2 function works
// fine for functions that take lvalue references but cannot be used to call a function that
// has an rvalue reference parameter

void g(int &i, int&& j)
{
	cout << i << " " << j << endl;
}


int main(int argc, char *argv[])
{
	int i = 1;
	int j = 2;

	f(i, 42);  //f changes its argument i
	Flip1(f, j, 42);  // f called through flip1 leaves j unchanged
	Flip2(f, j, 42);  // ok j is changed
	
	// Flip2(g, j, 42);  // error ,T2 is int, so t2 is rvalue ,but in func g, the last parater is int & --- a lvalue
	Flip(f, j, 42);
	Flip(g, j, 42);  	// When used with a function parameter that is an rvalue reference to template		
						// type parameter (T&&), forward preserves all the details about an
						// argument’s typename
	return 0;
}

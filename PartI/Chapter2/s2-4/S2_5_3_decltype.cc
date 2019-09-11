#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	
	int i = 42, *p = &i, &r = i;
	// r is a reference, so decltype(r) is a reference type, If we want the type to
    // which r refers, we can use r in an expression, such as r + 0, which is an expression
    // that yields a value that has a nonreference decltype
	decltype(r + 0) b; // ok: addition yields an int; b is an (uninitialized) int

	// when we dereference a pointer,
    // we get the object to which the pointer points. Moreover, we can assign to that object.
    // Thus, the type deduced by decltype(*p) is int&, not plain int
	
	// decltype(*p) c; // error: c is int& and must be initialized
	

	// decltype of a parenthesized variable is always a reference
	// A variable is an expression that can be the left-hand side of an assignment. 
	// decltype((i)) d;  // error: d is int& and must be initialized,
	decltype(i) e; // ok: e is an (uninitialized) int
	return 0;
}

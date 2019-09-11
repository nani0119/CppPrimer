#include <iostream>

using namespace std;
typedef char* pstring;

void print_var();

// defines bufSize as a constant. Any attempt to assign to bufSize is an error
const int bufSize  = 512;

// By default, const objects are local to a file
const int local2file = 10;

// using extern, share const var
extern const int constShared = 11;

int main(int argc, char *argv[])
{
	cout <<"const int bufSize = " <<bufSize << endl;

	// error: k is uninitialized const
	// const int k;
	
	cout << __FILE__<<":const int local2file = " << local2file << endl;
	cout << __FILE__<<":extern const int constShared = " << constShared << endl;
	print_var();	


	/* reference to const */
	// error: non const reference to a const object
	// int& r1 = bufSize;
	
	int i = 42;
	const int &r1 = i;      // we can bind a const int& to a plain int object
	const int &r2 = 42;     // ok: r1 is a reference to const
	const int &r3 = r1 * 2; // ok: r3 is a reference to const
	// int &r4 =  2;        // error: r4 is a plain, non const reference, 2 is rvalue
	// r2 = 0; 				// error: r2 is a reference to const
	
	/* pointer to const */
	// a pointer to const may not be used to change the object to which the pointer points
	// We may store the address of a const object only in a pointer to const
	
	const double pi = 3.14;   // pi is const; its value may not be changed 
	// double *ptr = &pi;     // error: ptr is a plain pointer 
	const double *cptr = &pi; // ok: cptr may point to a double that is const
	// *cptr = 42;            // error: cannot assign to *cptr
	double dval = 3.14;       // dval is a double; its value can be changed
	cptr = &dval;             // ok: but can't change dval through cptr

	/* const pointer */
	int errNumb = 0;
	int * const curErr = &errNumb; // curErr will always point to errNumb
	*curErr = 0;                   // ok: reset the value of the object to which curErr is bound
	
	const double * const pip = &pi; // pip is a const pointer to a const object
	// *pip = 2.72;                 // error: pip is a pointer to const

	/* top-level && low-level */
	// We use the term top-level const to indicate that the pointer itself is a const
	// When a pointer can point to a const object, we refer to that const as a low-level const.
	
	int *const p1 = &i; // we can't change the value of p1; const is top-level
	const int ci = 42;  // we cannot change ci; const is top-level
	const int *p2 = &ci; // we can change p2; const is low-level
	const int *const p3 = p2; // right-most const is top-level, left-most is not
	const int &r = ci; // const in reference types is always low-level
	// When we copy an object, top-level consts are ignored
	i = ci;     // ok: copying the value of ci; top-level const in ci is ignored
	p2 = p3;    // ok: pointed-to type matches; top-level const in p3 is ignored
	
	// low-level const is never ignored. When we copy an object,both objects must 
	// have the same low-level const qualification or there must e a conversion 
	// between the types of the two objects.we can convert a nonconst to const 
	// but not the other way round
	
	// int *p = p3; // error: p3 has a low-level const but p doesn't.
	p2 = p3; // ok: p2 has the same low-level const qualification as p3
	p2 = &i; // ok: we can convert int* to const int*
	// int &r = ci; // error: can't bind an ordinary int& to a const int object
	const int &rc3 = i; // ok: can bind const int& to plain int

	/* constexpr Variables */
	// ariables declared as constexpr are implicitly const 
	// and must be initialized by constant expressions
	
	constexpr int mf = 20; // 20 is a constant expression
	const int *p = nullptr; // p is a pointer to a const int
	constexpr int *q = nullptr; // q is a const pointer to int
	constexpr const int *o = nullptr; // o is a constant pointer to the const int i

	const pstring cstr = 0; // cstr is a constant pointer to char,    char* const cstr
	const pstring *ps;      // ps is a pointer to a constant pointer to char  char* const *ps
	return 0;
}

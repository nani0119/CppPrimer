#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i = 0;
	const int v2 = 1;  // top-level
	int v1 = 0;
	int *p1 = &v1;
    int &r1 = v1;
	const int *p2 = &v2;  // top-level 
    const int *const p3 = &i; // letf low-level, right top-level
    const int &r2 = v2;       // low-level, reference  is always low-level

	cout << "v1 = " << v1 << endl;
	r1 = v2; // change the value v1, top level
    cout << "v1 = " << v1 << endl;	

	// p1 = p2; // error, const to noconst
	p2 = p1;  // ok
	// p1 = p3;  // error 
    p2 = p3;  // ok 	
	return 0;
}

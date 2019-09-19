#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	const int n = 5;
	allocator<string> alloc;       // object that can allocate strings
	auto const p = alloc.allocate(n);    // allocate n unconstructed strings

	auto q = p;   // q will point to one past the last constructed element
	alloc.construct(q++);            // *q is the empty string
	alloc.construct(q++, 10, 'c');   // *q is cccccccccc
	alloc.construct(q++, "hi");      // *q is hi!

	cout << *p << endl;
	cout << *(p+1) << endl;
	cout << *(p+2) << endl;
	// cout << *q << endl;  // disaster: q points to unconstructed memory!
	
	while (q != p)
	{
		alloc.destroy(--q);  // free the strings we actually allocated
	}

	alloc.deallocate(p, n);  
	return 0;
}

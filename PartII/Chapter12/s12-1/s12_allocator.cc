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


	const int cnt = 20;
	vector<string> vec = {"1111", "2222", "3333", "4444","5555"};
	allocator<string> alc;
	auto p_alc = alc.allocate(cnt);

	auto q_alc = uninitialized_copy(vec.begin(), vec.end(), p_alc);
	uninitialized_fill_n(q_alc, 2, "xxxxxxxxxx");
	
	q_alc = q_alc +2;

	int i = 0;
	while((p_alc + i) < q_alc)
	{
		cout << *(p_alc+i) << " ";
		alc.destroy(p_alc + i);
		i++;
	}
	cout << endl;
	alc.deallocate(p_alc,cnt);

	return 0;
}

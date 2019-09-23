#include <iostream>
#include <string>


using namespace std;

template <typename T, unsigned N>
T* begin_t(T (&a)[N])
{
	if (a != nullptr)
		return &a[0];
	else
		return nullptr;
}

template <typename T, unsigned N>
T* end_t(T (&a)[N])
{
	if(a != nullptr && N > 0)
		return &a[N-1];
	else
		return nullptr;
}


int main(int argc, char *argv[])
{
	char s[] = "aaaaaaa";
	for(auto it = begin_t(s); it != end_t(s); it++) {
		cout << *it << " ";
	}
	cout << endl;

	int i[] = {1,2,3,4,5,6};
	for(auto it = begin_t(i); it != end_t(i); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename T>

bool compare(const T& lhs, const T& rhs)
{
	return less<T>()(lhs, rhs);
}


int main(int argc, char *argv[])
{
	cout << "1 < 2:" << (compare(1,2)? "true":"false") << endl;
	int a = 1, b = 2;
	cout << "&a < &b:" << (compare(&a,&b)? "true":"false") << endl;
	return 0;
}

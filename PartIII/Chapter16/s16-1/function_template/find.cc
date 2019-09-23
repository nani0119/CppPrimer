#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <functional>

using namespace std;

#if 1
template <typename T, typename U>
T find_t(const T& b, const T& e, U value)
{
	for(auto it = b; it != e; it++) {
		if(equal_to<U>()(*it, value))
			return it;
	}
	return e;
}
#else
template<class InputIterator, class T>
InputIterator find_t( InputIterator b, InputIterator e, const T& value)
{
	while(b!=e)
	{
		if(*b == value)
			return b;
		b++;
	}
	return e;
}

#endif


int main(int argc, char *argv[])
{
	vector<int> vec = {1,2,3,4,5,6,7,8,9,0};
	
	auto ret = find_t(vec.begin(), vec.end(), 3);
	if(ret != vec.end())
	{
		cout << "find 3 in vec:" <<*ret<< endl;
	}
	else
	{
		cout << "not find 3 in vec" << endl;
	}

	list<string> ls = {"aaaaaa", "bbbbbb", "ccccccc", "dddddddd"};

	string value = "ccccccc";
	auto ret_ls = find_t(ls.begin(), ls.end(), value);
	if(ret_ls != ls.end())
	{
		cout << "find:" << *ret_ls << endl;
	}

	int ia[] = {1,2,3,4,5,6};
	auto ret_ia = find_t(begin(ia), end(ia), 3);
	cout << "ret_ia:" << *ret_ia << endl;

	return 0;
}

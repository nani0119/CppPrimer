#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <vector>

using namespace std;

ostream& print(ostream& os, const string& s, char c)
{
	os << s << c;
	return os;
}

bool check_size(const string& str, string::size_type sz)
{
	return str.size() < sz;
}

int main(int argc, char *argv[])
{
	cout << boolalpha;
	// auto newCallable = bind(callable, arg_list);
	auto check_size6 = bind(check_size, placeholders::_1, 6); // _n represents newCallable nth parater, others is fixed

	cout << check_size6("hello") << endl;


	auto f = bind(print, ref(cout), placeholders::_1, '\n');
	f("hello");
	return 0;
}

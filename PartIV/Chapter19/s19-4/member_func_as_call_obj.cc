#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> svec = {"aaaaa","v","","bbbbbb"};

	// pointer of vector<*string> error
	function<bool (const string&)> fcn = &string::empty;
	auto it = find_if(svec.begin(), svec.end(), fcn);
	cout << it - svec.begin() << endl;

	// best 
	// Unlike function, mem_fn will deduce the type of the callable from the type of the pointer to member
	it = find_if(svec.begin(), svec.end(), mem_fn(&string::empty));
	cout << it - svec.begin() << endl;

	// pointer ok
	it = find_if(svec.begin(), svec.end(), bind(&string::empty, std::placeholders::_1));
	cout << it - svec.begin() << endl;
	return 0;
}

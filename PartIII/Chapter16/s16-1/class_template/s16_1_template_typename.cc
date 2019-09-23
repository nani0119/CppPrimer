#include <iostream>
#include <string>
#include <vector>

using namespace std;

// template <typename T>
// T::size_type * p;    // define a pointer  or a multiply?????, compiler interrepts a multiply

// When we want to inform the compiler that a name represents a type, we
// must use the keyword typename

// typename T::size_type* p;   // ok , a defination


template <typename T>

typename T::value_type top(const T& c)  // if do not add typename, compiler interrepts that top has type T::value_type
{
	if (!c.empty())
		return c.back();
	else
		return typename T::value_type();
}


int main(int argc, char *argv[])
{
	vector<string> vs = {"aaaa","bbbbb", "cccccc"};

	cout << top(vs) << endl;	
	return 0;
}

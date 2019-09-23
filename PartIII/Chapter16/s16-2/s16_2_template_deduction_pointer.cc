#include <iostream>
#include <string>
#include <vector>

using namespace std;



template <typename T> 
bool compare(const T& t1, const T& t2)
{
	return t1 < t2;
}


// overloaded versions of func; each takes a different function pointer type

void func(bool(*)(const string&, const string&))
{
	cout << "compare string" << endl;
}
void func(bool(*)(const int&, const int&))
{
	cout << "compare int" << endl;
}


int main(int argc, char *argv[])
{
	cout << boolalpha;
	int a =1, b=2;
	bool (*pf) (const int& t1, const int& t2) = compare;   // T is int
	cout << pf(a,b) << endl;

	
	// func(compare); // error: which instantiation of compare
	func(compare<int>);
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

template <typename ... T>
void g(T... t)
{
	cout << "number of type parameters:" << sizeof...(T) << endl;
	cout << "number of function parameters:" << sizeof...(t) <<endl;
}


int main(int argc, char *argv[])
{
	int i = 1;
	double d = 2.0;
	long l = 3l;
	string s = "hi";

	g(i,i,d);
	g(i,d,l,s);
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

class NoOutput
{
	friend ostream& operator<<(ostream& os, const NoOutput& no);
};

ostream& operator<<(ostream& os, const NoOutput& no)
{
	os << "NoOutput";
	return os;
}

template <typename T>
ostream& print(ostream& os, const T& t)
{
	os << t;
	return os;
}

template <typename T, typename ... Args>
ostream& print(ostream& os, const T& t, const Args ... rest)
{
	os << t << ",";
	return print(os,rest...);
}


int main(int argc, char *argv[])
{
	string s = "aaaaaa";
	NoOutput no;
	print(cout, 1,"as",2.0, s, no) << endl; 
	return 0;
}

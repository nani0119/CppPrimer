#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class NoOutput
{
	friend ostream& operator<<(ostream& os, const NoOutput& no);
};

ostream& operator<<(ostream& os, const NoOutput& no)
{
	os << "class(NoOutput)";
	return os;
}

template <typename T>
ostream& print(ostream& os, const T& t)
{
	os << t << endl;
	return os;
}

template <typename T,typename ... Args>
ostream& print(ostream& os, const T& t, const Args ... rest)
{
	os << t << endl;
	print(os,rest...);
	return os;
}

#if 0
string debug_rep(const char* t)
{
	ostringstream ret;
	ret << "pointer: " << &t << " c " << '"'<< t << '"';
	return ret.str();
}
#endif

template <typename T>
string debug_rep(const T* t)
{
	ostringstream ret;
	ret << "pointer: " << t;
	return ret.str();
}

template <typename T>
string debug_rep(const T& t)
{
	ostringstream ret;
	ret << debug_rep(&t);
	ret << " l " << t;
	return ret.str();
}

template <typename T>
string debug_rep(const T&& t)
{
	ostringstream ret;
	ret << debug_rep(&t);
	ret << " r " << t;
	return ret.str();
}

template <>
string debug_rep(const char* t)
{
	ostringstream ret;
	ret << "pointer: " << &t << " c " << '"'<< t << '"';
	return ret.str();
}

template <typename ... Args>
void err_msg(ostream& os, Args&& ... rest)
{
	// print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an)
	print(os,debug_rep(std::forward<Args>(rest))...);
}

void err_msg(ostream& os)
{
}


int main(int argc, char *argv[])
{
	int i = 0;
	double d = 1.0;
	long l = 2l;
	float f = 3.0f;
	string s = "aaaaaaaa";
	const char* str =  "bbbbbbbb";
	NoOutput  no;
	const int & ri = i;
	cout << "=============================" << endl;
	err_msg(cout, i);
	cout << "=============================" << endl;
	err_msg(cout, i , d, l, f, s, str,no);
	cout << "=============================" << endl;
	err_msg(cout);
	cout << "=============================" << endl;
	err_msg(cout, i, &i);
	cout << "=============================" << endl;
	err_msg(cout, 10+3,3.0,"xxxxxxx");
	cout << "=============================" << endl;
	err_msg(cout,make_shared<int>(6));
	cout << "=============================" << endl;
	// err_msg(cout,vector<int>({1,2,3}));
	return 0;
}

#include <iostream>
#include <string>
#include <initializer_list>
#include <stdarg.h>
using namespace std;


void usage_initializer_list()
{
	initializer_list<string> lst{"aa","bb","cc","dd"};
	cout <<"lst.size():" << lst.size() << endl;
	for(auto it = lst.begin(); it != lst.end(); it++) {
		cout << *it << endl;
	}

}


void err_msg(initializer_list<string> msg)
{
	for(auto it = msg.begin(); it != msg.end(); it++) {
		cout << *it << endl;
	}
}

//====================================================================

double add(int num, ...)
{
	double sum = 0.0;
	va_list vl;     		 //va_list指针，用于va_start取可变参数，为char*
	va_start(vl,num);        //取得可变参数列表中的第一个值
	for (int i = 0; i < num; ++i)
	{
		sum += va_arg(vl, double);
	}
	va_end(vl);
	
	return sum;
}
//====================================================================

template <typename T>
void foo(const T& t)
{
	cout << t << endl;
}

template <typename T, typename ... Args>
void foo(const T& t, const Args& ... args)
{
	// cout <<"varying paramers number: "<< sizeof...(args) << endl;
	cout << t << ",";
	foo(args...);
}

int main(int argc, char *argv[])
{
	usage_initializer_list();
	cout << "==================================================" << endl;
	err_msg({"ab","bc", "cd"});
	cout << "==================================================" << endl;
	cout << "sum:"<<add(4,1.0,2.0,3.0,4.0) << endl;
	cout << "==================================================" << endl;
	int i = 0; 
	double d = 3.14; 
	string s = "how now brown cow";

	foo(i, s, 42, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("hi");
	return 0;
}

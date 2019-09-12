#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <list>
#include <utility>

using namespace std;

//=======================================
// return a list
vector<string> process()
{
	return {"aaa","bbbb","cccc"};
}

tuple<string, vector<double>, int, list<int>> 
return_tuple_list()
{
	return make_tuple(string("constants"), vector<double>({3.14, 2.718}), 42, list<int>({0,1,2,3,4,5}));
}

pair<string,string> return_pair_list()
{
	return make_pair("aaaaa","bbbbbb");
}

//=======================================
// Returning a Pointer to an Array

//func takes an int argument and returns a pointer to an array of ten ints
auto func(int i) -> int(*)[10]
{
	static int a[10] = {1,2,3,4};
	int(*pa)[10] = &a;
	return pa;
}

int b[10];

// decltype(b)* func(int i)  // the same as auto func(int i) -> int(*)[10]
// {
// }

//========================================
int main(int argc, char *argv[])
{
	auto v = process();
	cout << v[0] << endl;
	cout << "===================================" << endl;
	auto tu = return_tuple_list();
	cout << get<0>(tu) << endl;
	cout << "===================================" << endl;
	auto p = return_pair_list();
	cout << p.first << "   " << p.second << endl;
    cout << "===================================" << endl;
	int(*pa)[10] = func(4);
	cout << *pa[0] << endl;  // 指向指针的指针
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

void display_split()
{
	cout << "==============================================" << endl;
}

bool isShorter(const string& s1, const string& s2)
{
	return s1 < s2;
}

int main(int argc, char *argv[])
{
	cout << boolalpha;
	// lambda expression
	// [capture list] (paramter list) -> return type {function body}
	
	auto f = [] {return 42;};   // capture list and function body can not omit
	cout << f() << endl;
	display_split();

	auto f1 = [](const string& s1, const string& s2) {return s1.size() < s2.size();};
	cout << f1("aaaa", "bbbbbb") << endl; 
	display_split();

	size_t sz1 = 4;
	size_t sz2 = 1;
	auto f2 = [sz1, sz2](const string& s) {return s.size() < (sz1 + sz2);};
	cout << f2("1234567") << endl;
	display_split();

	vector<string> vs = {"123","1", "11111","2222","11","1111","2222","555"};
	vector<string>::size_type sz = 4;
	auto wc = find_if(vs.begin(), vs.end(), [sz](const string& s){return s.size() == sz;});
	cout << *wc << endl;
	display_split();

	// for_each
	for_each(wc, vs.end(), [](const string& s){cout << s << " ";});
	cout << endl;
	display_split();

	// capture by value or reference
	
	size_t sz3 = 45;
	size_t sz4 = 3;
	auto fv = [=,&sz4](){return sz3+sz4;};  // default value , sz4 reference
	cout << fv() << endl;
	display_split();

	auto fr = [&,sz4](){return sz3 + sz4;};  // default reference ,sz4 value
	cout << fr() << endl;
	display_split();

	auto fc = [&](){++sz3;};
	fc();
	cout << sz3 << endl;

	auto fc1 = [sz4] () mutable  {return ++sz4;};  // if no mutable ,compile error, gen lambda class using sz4 4;
	sz4 = 0;
	auto j = fc1();
	
	cout << j << endl;
	display_split();

	// transform
	vector<int> vi = {-1,-2, -3, 4,-5,-7};
	transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int {if(i > 0) return i; else return -i;});
	for(auto it = vi.begin(); it != vi.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

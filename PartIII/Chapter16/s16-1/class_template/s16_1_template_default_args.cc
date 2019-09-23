#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

template <typename T, typename F = less<T>>
bool compare(const T& t1, const T& t2, F f = F())
{
	return f(t1, t2);
}


template <typename T = int>
class Numbers
{
	public:
	Numbers(T v = 0): val(v) {}

	T showNumber()
	{
		return sizeof(val);
	}
private:
	T val;
};



int main(int argc, char *argv[])
{
	cout << boolalpha;
	cout << compare(string("aaaaa"), string("bbbbbb")) << endl;
	cout << compare(2,1) << endl;
	cout << compare(string("45"), string("3")) << endl;
	cout << compare(string("45"), string("3"), isShorter) << endl;
	
	Numbers<double> nd(12.0);
	cout << nd.showNumber() << endl;

	Numbers<> ni(12);   // empty <> says we want the default type
	cout << ni.showNumber() << endl;
	return 0;
}

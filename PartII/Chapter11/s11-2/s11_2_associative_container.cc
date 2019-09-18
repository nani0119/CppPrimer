#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <cctype>
#include <utility>

using namespace std;

pair<int, int> ret_pair(vector<int> v)
{
	if(!v.empty())
	{
		return {v.back(), v.size()};
	}
	else
	{
		return pair<int, int>();
	}
}

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() > s2.size();
}

int main(int argc, char *argv[])
{
	ostream_iterator<int> out(cout, " ");
	vector<int> ivec(20);
	int i = 0;
	for_each(ivec.begin(), ivec.end(),[&](int& j){ j = i++;if(i == 10) i = 0;});

	copy(ivec.begin(), ivec.end(), out);
	cout << endl;
	set<int> iset(ivec.begin(), ivec.end());
	multiset<int> mset(ivec.begin(), ivec.end());

	copy(iset.begin(), iset.end(), out);
	cout << endl;
	copy(mset.begin(), mset.end(), out);
	cout << endl;


	// set key compare function
	// auto key_compare_f = [](const string& s1, const string& s2)-> bool {return s1.size() > s2.size();};
	vector<string> vs = {"1", "22", "333", "4444", "5555", "66666"};
	multiset<string, decltype(isShorter)*> ms(isShorter);
	copy(vs.begin(), vs.end(), inserter(ms, ms.begin()));
	for(auto it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	map<string, int, decltype(isShorter)*> map_shorter(isShorter);
	for_each(vs.begin(), vs.end(), [&](const string& s){map_shorter.insert(map_shorter.end(), make_pair(s,s.size()));});
	for(auto it = map_shorter.begin(); it != map_shorter.end(); it++) {
		cout << it->first << ":" << it->second << endl;
	}
	cout << endl;

	// pair
	
	pair<int, int> p1;
	pair<int, int> p2(1,1);
	pair<int, int> p3 = {1,1};
	pair<int, int> p4 = make_pair(1,1);


	return 0;
}

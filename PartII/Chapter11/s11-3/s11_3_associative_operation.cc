#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <list>

using namespace std;


int main(int argc, char *argv[])
{
	// key_type       type of key for the container
	// mapped_type	  type associated with each key, only for map
	// value_type     for set, the same as key_type. for map, pair<const key_type, mapped_type>
	
	set<string>::key_type v1;           // v1 is string
	set<string>::value_type v2;         // v2 is string
	map<string, int>::key_type v3;      // v3 is sting
	map<string, int>::mapped_type v4;   // v4 is int
	map<string, int>::value_type v5;    // v5 is pair<const string, int>

	v1 = "set key_type v1";
	v2 = "set value_type v2";
	v3 = "map key_type v3";
	v4 = 4;
	// v5.first;  const 
	v5.second = 5;

	set<int> si = {1,2,3,4,5};
	set<int>::iterator s_it = si.begin();
	// *s_it = 2;    // error, key_type in associate container  is const
	cout << *s_it << endl;

	// insert
	cout << boolalpha;
	map<string, int>  m;
	multimap<string, int> mm;

	pair<map<string,int>::iterator,bool> ret = m.insert(pair<string, int>("1st",1));
	cout <<"{"<< ret.first->first	<< "," << ret.first->second<<"}" <<":" <<ret.second <<endl;

	// insert false,dumplication
	auto ret_f = m.emplace(pair<string,int>("1st",1));
	cout <<"{" << ret_f.first->first << "," << ret_f.first->second << "}" << ":" << ret_f.second << endl;
	cout << "=================================================" << endl;

	multimap<string,int>::iterator mm_ret = mm.insert(make_pair("1st",1));
	cout << mm_ret->first << " " << mm_ret->second << endl;
	cout << "=================================================" << endl;
	// ok
	auto mm_ret_t = mm.emplace(pair<string,int>("1st",1));
	for(auto it = mm.begin(); it != mm.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << "=================================================" << endl;
	vector<pair<string, int>> vp = { 
										{"1st",1},
										{"2nd",2},
										{"3th",3},
										{"4th",4},
										{"5th",5}
									};
	 m.insert(vp.begin(), vp.end());
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }	
	 cout << "=============================================" << endl;

	 m.insert({{"6th",6},{"7th",7}});
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }	
	 cout << "=============================================" << endl;

	 map<string,int>::iterator m_ret = m.insert(m.end(),{"1st",1});
	 cout << m_ret->first << " " << m_ret->second << endl;
	 cout << "=============================================" << endl;
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }	
	 cout << "=============================================" << endl;

	 // erase
	 
	 map<string,int>::size_type n = m.erase("1st");
	 cout << n << endl;
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }	
	 cout << "=============================================" << endl;

	 map<string,int>::iterator erase_ret = m.erase(m.begin());
	 cout << erase_ret->first <<" " << erase_ret->second << endl;
	 cout << "=============================================" << endl;
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }	
	 cout << "=============================================" << endl;

	 map<string,int>::iterator e = m.erase(++m.begin(), --m.end());
	 cout << e->first <<" " << e->second << endl;
	 cout << "=============================================" << endl;
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }	
	 cout << "=============================================" << endl;

	 // access
	 cout << m["7th"] << endl;
	 cout << m["aa"] << endl;   // if key is not in container, add a new value
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }	
	 cout << "=============================================" << endl;

	 cout << m.at("7th") << endl;
	 // cout << m.at("bb") << endl;   // if key is not in container, throw out_of_range
	 
	 cout << "=============================================" << endl;
	 map<string,int>::iterator m_find = m.find("7th");

	 cout << "=============================================" << endl;
	 auto count = m.count("aa");
	 cout << "=============================================" << endl;
	 cout << count << endl;

	 m.insert(vp.begin(), vp.end());
	 m.insert({"9th",9});
	 m.insert({"ff",15});
	 m.insert({"cc",13});
	 cout << "=============================================" << endl;
	 for(auto it = m.begin(); it != m.end(); it++) {
	 	cout << "{"<<it->first << "," << it->second << "}" << endl;
	 }
	 
	 cout << "=============================================" << endl;

	 map<string,int>::iterator m_lower_bound = m.lower_bound("8th"); 
	 cout << m_lower_bound->first << " " << m_lower_bound->second << endl;

	 cout << "=============================================" << endl;
	 map<string,int>::iterator m_upper_bound = m.lower_bound("ee"); 
	 cout << m_upper_bound->first << " " << m_upper_bound->second << endl;

	 cout << "=============================================" << endl;
	 pair<multimap<string,int>::iterator, multimap<string,int>::iterator> mm_range = mm.equal_range("1st");
	 cout << (mm_range.second != mm_range.first) << endl;
	 cout << "=============================================" << endl;
	 pair<multimap<string,int>::iterator, multimap<string,int>::iterator> mm_range_f = mm.equal_range("cc");
	 cout << (mm_range_f.second == mm_range_f.first) << " " << (mm_range_f.first == mm.end()) << endl;
	return 0;
}

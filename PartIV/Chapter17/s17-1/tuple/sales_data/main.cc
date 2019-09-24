#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include "Sales_data.h"



using namespace std;
//#define PAIR_T

bool compareIsbn(const Sales_data& lhs, const Sales_data& rhs)
{
	return lhs.isbn() < rhs.isbn();
}

#ifdef PAIR_T
typedef pair<vector<Sales_data>::size_type, pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> matches_pair;
vector<matches_pair> findBookForPair(const vector<vector<Sales_data>>& files, const string book)
{

	vector<matches_pair> ret;
	for(auto it = files.cbegin(); it != files.cend(); it++) {
			auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
			if(found.first != found.second)
			{
				ret.push_back(make_pair(it-files.cbegin(), make_pair(found.first, found.second)));
			}
		}
	return ret;
}

void reportReusltForPair(istream& is, ostream& os, const vector<vector<Sales_data>>& files)
{
	string s;
	while(cin >> s)
	{
		auto trans = findBookForPair(files, s);
		if(trans.empty())
		{
			cout << s << " not found in any stores" << endl;
			continue;
		}
		for(const auto& store: trans)
		{
			os << "store " << store.first << " sales: "
				<< accumulate(store.second.first, store.second.second, Sales_data(s))
				<< endl;
		}
	}
}

#endif

typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;
vector<matches> findBook(const vector<vector<Sales_data>>& files, const string book)
{
	vector<matches> ret;
	for(auto it = files.cbegin(); it != files.cend(); it++) {
			auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
			if(found.first != found.second)
			{
				ret.push_back(make_tuple(it-files.cbegin(), found.first, found.second));
			}
		}
	return ret;
}

void reportReuslt(istream& is, ostream& os, const vector<vector<Sales_data>>& files)
{
	string s;
	while(cin >> s)
	{
		auto trans = findBook(files, s);
		if(trans.empty())
		{
			cout << s << " not found in any stores" << endl;
			continue;
		}
		for(const auto& store: trans)
		{
			os << "store " << get<0>(store) << " sales: "
				<< accumulate(get<1>(store), get<2>(store),Sales_data(s))
				<< endl;
		}
	}
}
int main(int argc, char* argv[])
{
	vector<vector<Sales_data>> files;
	vector<Sales_data> item;
	
	for (int i = 0; i < 5; ++i) {
		
		Sales_data sd("111",2,4);
		item.push_back(sd);	
	}
	files.push_back(item);
	for (int i = 0; i < 5; ++i) {
		
		Sales_data sd("222",2,4);
		item.push_back(sd);	
	}
	files.push_back(item);
#ifndef PAIR_T
	reportReuslt(cin,cout,files);
#else
	reportReusltForPair(cin,cout,files);
#endif
	return 0;
}

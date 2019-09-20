#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <memory>
#include <algorithm>
#include <numeric>

#ifndef TEXTQUERY
#define TEXTQUERY 
#include "QueryResult.h"
using namespace std;

class QueryResult;

class TextQuery
{
	public:
		using line_no=vector<string>::size_type;
		TextQuery(ifstream& is);
		QueryResult query(const string& s) const;
		void debug();
	private:
		shared_ptr<vector<string>> file;
		map<string, shared_ptr<set<line_no>>> wm;
};
#endif /* ifndef TEXTQUERY */

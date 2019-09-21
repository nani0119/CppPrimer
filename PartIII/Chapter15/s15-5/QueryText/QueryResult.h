#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <set>

#ifndef QUERYRESULT
#define QUERYRESULT 
#include "debug.h"
using namespace std;

class QueryResult
{
	friend ostream& print(ostream& os, const QueryResult&);
	public:
		using line_no = vector<string>::size_type;
		QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f);
		set<line_no>::iterator begin() const;
		set<line_no>::iterator end() const;
		shared_ptr<vector<string>> get_file() const;
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<vector<string>> file;
};
ostream& print(ostream& os, const QueryResult& );
#endif /* ifndef QUERYRESULT */

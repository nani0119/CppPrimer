#include "QueryResult.h"


QueryResult::QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f): sought(s), lines(p), file(f) 
{
}

set<QueryResult::line_no>::iterator QueryResult::begin() const
{
	return lines->begin();
}

set<QueryResult::line_no>::iterator QueryResult::end() const
{
	return lines->end();
}

shared_ptr<vector<string>> QueryResult::get_file() const
{
	return file;
}
ostream& print(ostream& os, const QueryResult& qr)
{
#if DEBUG 
	cout << "QueryResult print" << endl;
#endif
	os << qr.sought << " occurs " << qr.lines->size()  << " "
	   << (qr.lines->size() > 1? "time": "times")<< endl;

	os << "===========================output==================="<<endl;
#if 0
	for(auto num: *qr.lines)
	{
		os << "\t(line " << num + 1 << ") " 
			<< *(qr.file->begin() + num) << endl;
	}
#else
	for(auto it = qr.begin(); it != qr.end(); it++) {
		os << "\t(line " << *it + 1 << ") "
			<< *(qr.get_file()->begin() + *it) << endl;
	}
#endif
	return os;

}

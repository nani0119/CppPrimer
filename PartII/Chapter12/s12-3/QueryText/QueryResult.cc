#include "QueryResult.h"


QueryResult::QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f): sought(s), lines(p), file(f) 
{
}

ostream& print(ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size()  << " "
	   << (qr.lines->size() > 1? "time": "times")<< endl;

	os << "===========================output==================="<<endl;
	for(auto num: *qr.lines)
	{
		os << "\t(line " << num + 1 << ") " 
			<< *(qr.file->begin() + num) << endl;
	}
	return os;

}

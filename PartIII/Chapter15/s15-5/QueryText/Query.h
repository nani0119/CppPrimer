#ifndef QUERY_H
#define QUERY_H
#include <iostream>
#include <string>
#include <memory>
#include "debug.h"
using namespace std;
class QueryResult;
class Query_base;
class TextQuery;
class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
private:
	shared_ptr<Query_base> q;
	Query(shared_ptr<Query_base> query): q(query) {};

public:
	Query(const string& s);
	QueryResult eval(const TextQuery& t) const;
	string rep() const;
};

#endif /* QUERY_H */

#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <set>
#include "Query.h"
#include "debug.h"
using namespace std;

class Query;
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
};

class WordQuery: public Query_base 
{
	friend class Query;
private:
	string query_word;
	
	WordQuery(const string& s): query_word(s) 
	{
#if DEBUG
		cout << "WordQuery construct" << endl;
#endif
	};
	QueryResult eval(const TextQuery& t) const;
	string rep() const
	{
		return query_word;
	}
};

class NotQuery:public Query_base
{
	friend Query operator~(const Query&);
private:
	Query query;

	NotQuery(const Query& q): query(q) 
	{
#if DEBUG
		cout << "NotQuery constructor" << endl;
#endif
	};
	QueryResult eval(const TextQuery&) const;
	string rep() const
	{
		return "~(" + query.rep() + ")";
	}
};

class BinaryQuery: public Query_base
{
protected:
	Query lhs, rhs;
	string opSym;

	BinaryQuery(const Query &l, const Query &r, std::string s): lhs(l), rhs(r), opSym(s) {};
	string rep() const
	{
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
};

class AndQuery: public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
private:
	AndQuery(const Query& l, const Query& r): BinaryQuery(l, r, "&")
   	{
#if DEBUG
		cout << "AndQuery constructer" << endl;
#endif
	}
	QueryResult eval(const TextQuery& t) const;
};

class OrQuery: public BinaryQuery{
	friend Query operator|(const Query&, const Query&);
private:
	OrQuery(const Query& l, const Query& r): BinaryQuery(l, r, "|") 
	{
#if DEBUG
		cout << "NotQuery construct" << endl;
#endif
	}
	QueryResult eval(const TextQuery& t) const;
};
#endif /* QUERY_BASE_H */

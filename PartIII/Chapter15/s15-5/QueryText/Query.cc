#include "common.h"

Query::Query(const string& s): q(new WordQuery(s))
{
#if DEBUG
	cout << "Query construct" << endl;
#endif
}


QueryResult Query::eval(const TextQuery& t) const
{
#if DEBUG
	cout << "Query eval begin" << endl;
#endif	
	return q->eval(t);
}
string Query::rep() const
{
	return q->rep();
}
ostream& operator<<(ostream& os, const Query& query)
{
	os << query.rep();
}

Query operator~(const Query& operand)
{
#if DEBUG
	cout << " operator~ " << endl;
#endif
	return  shared_ptr<Query_base>(new NotQuery(operand));
}

Query operator&(const Query& lhs, const Query& rhs)
{
#if DEBUG
	cout << " operator& " << endl;
#endif	
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

Query operator|(const Query& lhs, const Query& rhs)
{
#if DEBUG
	cout << " operator| " << endl;
#endif
	return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

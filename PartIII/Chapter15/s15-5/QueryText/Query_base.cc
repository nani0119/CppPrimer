#include "common.h"
using namespace std;

QueryResult WordQuery::eval(const TextQuery& t) const
{
#if DEBUG
	cout << "WordQuery eval:" <<query_word<< endl;
#endif
	return t.query(query_word);
}

QueryResult OrQuery::eval(const TextQuery& t) const
{
#if DEBUG
	cout << "OrQuery eval" << endl;
#endif
	auto right = rhs.eval(t);
	auto left = lhs.eval(t);

	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& t) const
{
#if DEBUG
	cout << "AndQuery eval" << endl;
#endif
	auto left = lhs.eval(t);
	auto right = rhs.eval(t);
	auto ret_lines = make_shared<set<line_no>>();
	set_intersection(left.begin(), left.end(),
						right.begin(), right.end(),
						inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& t) const
{
#if DEBUG
		cout << "NotQuery eval" << endl;
#endif
	auto result = query.eval(t);

	auto ret_lines = make_shared<set<line_no>>();
	auto beg = result.begin();
	auto end = result.end();

	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n) {
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			beg++;
	}

	return QueryResult(rep(), ret_lines, result.get_file());
}

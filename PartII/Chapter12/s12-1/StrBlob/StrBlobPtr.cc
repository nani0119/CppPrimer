#include "StrBlobPtr.h"

using namespace std;


// StrBlobPtr::StrBlobPtr():curr(0)
// {
// }


// StrBlobPtr::StrBlobPtr(StrBlob& blob, size_t sz = 0): wptr(blob.data), curr(sz)
// {
// }


shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
	shared_ptr<vector<string>> ret = wptr.lock();
	if(!ret) {
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if(i > ret->size()){
		throw out_of_range(msg);
	}
	return ret;
}

string& StrBlobPtr::deref()  const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	curr++;
	return *this;
}

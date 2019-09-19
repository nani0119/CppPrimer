#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "StrBlob.h"

using namespace std;
class StrBlob;
class StrBlobPtr
{
	private:
		shared_ptr<vector<string>> check(size_t i, const string& msg) const;
		weak_ptr<vector<string>> wptr;
		size_t curr;
	public:
		StrBlobPtr(): curr(0){};
		StrBlobPtr(StrBlob& blob, size_t sz = 0): wptr(blob.data), curr(sz) {};
		string& deref() const;
		StrBlobPtr& incr();
		auto begin() -> decltype(wptr.lock()->begin())
		{
			return wptr.lock()->begin();
		}
		auto end() -> decltype(wptr.lock()->end())
		{
			return wptr.lock()->end();
		}
};

#endif /* STRBLOB_H */

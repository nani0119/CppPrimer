#ifndef BLOBPTR_H
#define BLOBPTR_H 
#include <iostream>
#include <vector>
#include <memory>
#include "Blob.h"
using namespace std;

template <typename T>
class BlobPtr{

private:
	weak_ptr<vector<T>> wptr;
	size_t curr;
	shared_ptr<vector<T>> check(size_t i, const string& msg) const;
public:
	BlobPtr():curr(0) {}
	BlobPtr(Blob<T> &b, size_t sz = 0):wptr(b.data),curr(sz) {}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	BlobPtr& operator++();
	BlobPtr& operator--();	
	BlobPtr operator++(int);
	BlobPtr operator--(int);
};


template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string& msg) const
{
	shared_ptr<vector<T>> ret = wptr.lock();
	if(!ret) {
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if(i > ret->size()){
		throw out_of_range(msg);
	}
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	// cout << "curr:" << curr << endl;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	// cout << "curr:" << curr << endl;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr<T> ret = *this;
	++*this;
	return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr<T> ret = *this;
	--*this;
	return ret;
}


#endif /* ifndef BLOBPTR_H */

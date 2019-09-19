#ifndef STRBLOB_H
#define STRBLOB_H
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class StrBlobPtr;
class StrBlob
{
public:
	friend class StrBlobPtr;
	typedef vector<string>::size_type  size_type;
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg) const;

public:
	StrBlob();
	// explicit	StrBlob(initializer_list<string> il);
	StrBlob(initializer_list<string> il);
	StrBlob(const StrBlob& b);
	StrBlob& operator=(const StrBlob& b);
	size_type size() const;
	bool empty() const;
	void push_back(const string& t);
	void pop_back();
	string& back() const;
	string& front() const;
	void print();
	StrBlobPtr begin();
	StrBlobPtr end();

};

#endif /* STRBLOB_H */

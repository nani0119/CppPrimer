#include "StrBlob.h"
#include "StrBlobPtr.h"

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {};

StrBlob::StrBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {};

StrBlob::StrBlob(const StrBlob& b):data(make_shared<vector<string>>())
{
	cout << "StrBlob copy construct"<< endl;
	for(auto it = (b.data)->begin(); it != (b.data)->end(); it++){
		data->push_back(*it);
	}
}

StrBlob& StrBlob::operator=(const StrBlob& b){

	cout << "StrBlob operator = " << endl;
	vector<string> tmp;
	for(auto it = (b.data)->begin(); it != (b.data)->end(); it++) {
		tmp.push_back(*it);
	}
	data.reset();
	data = make_shared<vector<string>>(tmp);
	return *this;
}

void StrBlob::check(size_type i, const string& msg) const
{
	if(i > data->size())
	{
		throw out_of_range(msg);
	}
	return;
}

string& StrBlob::back() const
{
	check(0,"back on empty StrBlob");
	return data->back();
}

string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}


StrBlob::size_type StrBlob::size() const
{
	return data->size();
}

bool StrBlob::empty() const
{
	return data->empty();
}

void StrBlob::push_back(const string& t)
{
	data->push_back(t);
}

void StrBlob::print()
{
	for(auto it = data->begin(); it != data->end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

#ifndef BLOB_H
#define BLOB_H 

#include <iostream>
#include <memory>
#include <vector>
#include <initializer_list>

using namespace std;
template <typename T> 
class BlobPtr;

template <typename T>
class Blob;

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs);

template <typename T>
class Blob {
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>& lhs, const Blob<T>& rhs);
public:
	typedef typename vector<T>::size_type size_type;
	typedef T value_type;

	Blob();
	Blob(initializer_list<T> il);

	// template <typename It>
	// Blob(It b, It e): data(make_shared<vector<T>>(b, e)) {}

	template <typename It>
	Blob(It b, It e);

	size_type size() const {return data->size();}
	bool empty() const { return data->empty();}
	void push_back(const T& t) { data->push_back(t);}
	void push_back(T&& t) {data->push_back(std::move(t));}
	void pop_back();
	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string& msg) const;
};


template<typename T>
template <typename It>
Blob<T>::Blob(It b, It e): data(make_shared<vector<T>>(b, e)) 
{

}



template <typename T>
void Blob<T>::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template <typename T>
Blob<T>::Blob():data(make_shared<vector<T>>())
{
}

template <typename T>
Blob<T>::Blob(initializer_list<T> il): data(make_shared<vector<T>>(il))
{
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
bool operator==(Blob<T>& lhs, Blob<T>& rhs)
{
	bool ret = lhs.size() == rhs.size();
	if (!ret)
	{
		return false;
	}
	else
	{
		for(auto i = 0; i < lhs.size(); i++)
		{
			if(lhs[i] == rhs[i])
				continue;
			else
				return false;
		}
	}
	
	return true;
}
#endif /* ifndef BLOB_H */

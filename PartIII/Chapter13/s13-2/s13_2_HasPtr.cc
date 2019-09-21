#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const std::string &s = std::string()):
			ps(new std::string(s)), i(0) {
			   	// cout<<"HasPtr construct"<<endl;
			};
	HasPtr(const HasPtr& p): ps(new string(*(p.ps))), i(p.i) {
		// cout << "HasPtr copy construct:"<< *ps <<endl;
	};

	~HasPtr()
	{
		// cout << "HasPtr destroy"<<endl;
		delete ps;
	}
	HasPtr& operator=(const HasPtr& h)
	{
		// cout << "HasPtr copy-assignment function"<<endl;
		if(ps != nullptr)
		{
			delete ps;
			ps = nullptr;
		}
		auto tmp = new string(*(h.ps));
		i = h.i;
		delete ps;
		ps = tmp;
	}

	bool operator<(const HasPtr& h)
	{
		return *ps < *(h.ps);
	}
	string getStr() {
		return *ps;
	}
private:
	std::string *ps;
	int i;
};

void swap(HasPtr& l, HasPtr& r){
	cout << "swap" <<endl;
	swap(l.ps, r.ps);
	swap(l.i, r.i);
}

int main(int argc, char *argv[])
{

	HasPtr h1("aaaaaaaaaaaa"), h3("bbbbbbbbbbbbbbbb");
	HasPtr h2 = h1;
	h3 = h1;
	cout << "H3:" << h3.getStr()<< endl;

	HasPtr h4("111111111111"), h5("2222222222222222");
	swap(h4, h5);
	cout << "h5:"<<h5.getStr() <<endl;
	
	return 0;
}

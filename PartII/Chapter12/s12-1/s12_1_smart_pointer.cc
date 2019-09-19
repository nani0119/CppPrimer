#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

class Default
{
public:
	Default(int a): i(a)
	{
		cout << "create object Default" << endl;
	}
	~Default()
	{
		cout << "release object Default" << endl;
	}
	void show()
	{
		cout << i << endl;
	}
private:
	int i = 0;
};
shared_ptr<Default> ret_Default()
{
	return make_shared<Default>(45);
}


int main(int argc, char *argv[])
{
	cout << boolalpha;
	shared_ptr<Default> D = ret_Default();
	D->show();


	shared_ptr<int> p = make_shared<int>(42);
	cout << *p << endl;
	shared_ptr<string> ps = make_shared<string>();  // point empty string	
	*ps = "test";
	cout << *ps << " " << ps->size() << endl;

	shared_ptr<string> q(ps);
	cout << q.use_count() <<  "  " << ps.unique() << endl; 

	shared_ptr<string> q1 = q;
	cout << q.use_count() <<  "  " << q1.unique() << endl; 
	
	string* q2 = q.get();
	cout<< *q2 << " " << q.use_count() <<  "  " << q1.unique() << endl; 
	
	shared_ptr<string> q3;
	q.swap(q3);
	cout << q1.use_count() <<  "  " << q3.unique() << endl;
	swap(q,q3);
	cout << q.use_count() <<  "  " << q.unique() << endl;


	// weak pointer, do not change reference
	weak_ptr<string> w(ps);

	cout<<"weak ptr:" << q.use_count() <<  "  " << q.unique()  << " "<<w.use_count()<< endl;
	cout << "weak ptr:"<<w.expired() << endl;  // sp referece > 0
	shared_ptr<string> sp_w = w.lock();
	cout<<"weak ptr:" << sp_w.use_count() <<  "  " << sp_w.unique()  << " "<<ps.use_count()<< endl;
	w.reset(); // make w null
	cout<<"weak ptr:" << w.expired()<< endl;

    // reset 
	q.reset();   // subtract count of shared_ptr ps
	cout << ps.use_count() <<  "  " << ps.unique() << endl;

	q.reset(new string("qqqqqq"));
	cout << p.use_count() <<  "  " << p.unique() << endl;


	// define deleter
	auto deleter = [](int* i ) -> void  {cout << "delete i = " <<*i<< endl; delete i;};
	shared_ptr<int> pd(new int(42), deleter);
	pd.reset(new int(40),deleter);


	return 0;
}

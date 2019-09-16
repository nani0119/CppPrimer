#include <iostream>
#include <list>
#include <vector>
#include <forward_list>
#include <array>
#include <deque>

using namespace std;

void print(deque<string>& ds)
{
	if(ds.size() == 0)
	{
		cout << "no more data" << endl;
		return;
	}
	for(auto it = ds.begin(); it != ds.end(); it++) {
		cout << *it <<" ";
	}
	cout << endl;
	return;
}

int main(int argc, char *argv[])
{
	// add elements
	deque<string> ds;
	cout << "push data back:" << endl;
	ds.push_back("aa");    // not valid for forward_list
	print(ds);

	cout << "push data front:" << endl;
	ds.push_front("bb");  // not valid for vector and string
	print(ds);

	cout << "emplace data back:" << endl;
	ds.emplace_back("cc"); // not valid for forward_list
	print(ds);

	cout << "empalce data front:" << endl;
	ds.emplace_front("dd");   // not valid for vector and string
	print(ds);

	cout << "empalce data:" << endl;
    auto it1 = ds.emplace(ds.end(),"ee");
	print(ds);
	cout << *it1 << endl;

	cout << "insert data:" << endl;
	auto it2 = ds.insert(ds.end(),"ff");
	print(ds);
	cout << *it2 << endl;

	cout << "insert n datas:"<<endl;
	auto it3 = ds.insert(ds.begin(), 0, "gg");
	print(ds);
	cout << *it3 << endl;

	auto it4 = ds.insert(ds.end(), 3, "hh");
	print(ds);
	cout << *it4 <<" "<< *(it4++) << endl;

	cout << "insert datas by iterator:" << endl;
	vector<string> vs = {"ii","jj"};
	auto it5 = ds.insert(ds.end(), vs.begin(), vs.end());
	print(ds);
	cout << *it5 << endl;

	cout << "insert data by list:" << endl;
	auto it6 = ds.insert(ds.end(),{"kk","ll"});
	print(ds);
	cout << *it6 << endl;
	
	// access element
	if (!ds.empty()){
		cout << "c.back(): " << ds.back() << endl;   // not valid for forward_list
		cout << "c.front():" << ds.front() << endl;
		cout << "c[2]: "  << ds[2] << endl;          // only for vecotr string deque and array
		cout << "c.at(2):" << ds.at(2) << endl;
	} else {
		cout << "container is empty" << endl;
	}
	
	if(!ds.empty())
	{
		cout << "c.pop_back():" << endl;
	   	ds.pop_back();  // not valid for forward_list
		print(ds);
	} 
	cout << "c.pop_front():"  << endl;   
	ds.pop_front();   // not valid for vector and string
	print(ds);

	if(!ds.empty())
	{
		cout << "c.erase():" << endl;
		auto it7 = ds.erase(ds.begin());
		print(ds);
		cout << *it7 << endl;	
	}

	cout << "erase data by iterator:" << endl;
	auto it8 = ds.erase(ds.begin()+1, ds.end()-1);
	print(ds);
	cout << *it8 << endl;

	cout << "clear:" << endl;
	ds.clear();
	print(ds);


	return 0;
}

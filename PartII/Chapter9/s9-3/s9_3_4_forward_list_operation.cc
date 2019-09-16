#include <iostream>
#include <forward_list>
#include <string>
#include <list>
#include <vector>
#include <array>

using namespace std;

void print(forward_list<int>& fwd)
{
	if(!fwd.empty())
	{
		for(auto it = fwd.begin(); it != fwd.end(); it++) {
			cout << *it << " ";
		}
		cout << " " << endl;
	}
	else
	{
		cout << "no more data" << endl;
	}
}

int main(int argc, char *argv[])
{
	forward_list<int> fwd = {0,1,2,3,4,5,6,7,8,9};
	cout << "origin data:" << endl;
	print(fwd);

	cout << "change data:" << endl;
	auto prev = fwd.before_begin();
	auto curr = fwd.begin();
	while(curr != fwd.end())
	{
		if (*curr % 2)
		{
			curr = fwd.erase_after(prev);
		}
		else
		{
			prev = curr;
			curr++;
		}
	}
	print(fwd);

	cout << "insert data:" << endl;
	auto it1 = fwd.insert_after(fwd.before_begin(),1);
	print(fwd);
	cout << *it1 << endl;

	cout << "insert list:" << endl;
	auto it2 = fwd.insert_after(fwd.before_begin(),{3,5});
	print(fwd);
	cout << *it2 << endl;

	cout << "insert data by iterator:" << endl;
	vector<int> vs = {7,9};
	auto it3 = fwd.insert_after(fwd.before_begin(),vs.begin(),vs.end());
	print(fwd);
	cout << *it3 << endl;

	cout << "insert n datas:" << endl;
	auto it4 = fwd.insert_after(fwd.before_begin(), 2, 11);
	print(fwd);
	cout << *it4 << endl;

	cout << "emplace after:" << endl;
	auto it5 = fwd.emplace_after(fwd.before_begin(),13);
	print(fwd);
	cout << *it5 << endl;

	cout << "erase after a elememt:" << endl;
	auto it6 = fwd.erase_after(fwd.before_begin());
	print(fwd);
	cout << *it6 << endl;

	cout << "erase data by iterator:" << endl;
	auto b = fwd.begin();
	decltype(b) e;
	for(auto it = fwd.begin(); it != fwd.end(); it++) {
		if (*it == 0){
			 e = it;
			 break;
		}
	}
	auto it7 = fwd.erase_after(b, e);  // after b, not includ b and e
	print(fwd);
	cout << *it7 << endl;

	cout << "clear:" << endl;
	fwd.clear();
	print(fwd);
	return 0;
}

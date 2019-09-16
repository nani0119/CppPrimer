#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	forward_list<double> fwd{1.0, 2.0, 3.0, 4.0,5.0};
	forward_list<double> fwd1 = {1.0,2.0};
	forward_list<double> fwd2(fwd1);
	forward_list<double> fwd3 = fwd2;
	forward_list<double> fwd4(fwd.begin(), fwd.end());

	array<int ,10> arr = {1};
	cout << "output array<int,10> data:" << endl;
	for(auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "change array value:" << endl;
	arr[0] = 3;
	for(auto it = arr.begin(); it != arr.end(); it++) {
		cout << *it << " ";
	}
    cout << endl;

	cout << "array max size:" << endl;
	cout << "arr.maxsize(): " << arr.max_size() << endl; 

	vector<string> vs{"aa", "bb", "cc","dd","ee"};
	vector<string>::iterator vs_it_begin = vs.begin();   // type of iterator for this container type
	vector<string>::iterator vs_it_end = vs.end();
	vector<string>::difference_type vs_diff_type =vs_it_end - vs_it_begin;  // hold the ditance between two iteators
	cout << "vector<string>::difference_type: " << vs_diff_type << endl;  
	
	vector<string>::size_type sz = vs.size();
	cout << "vector<string>::size_type: " << sz << endl;    // hold the size

	vector<string>::value_type val = vs[0];     // element value
	cout << "vector<string>::value_type: " << val << endl; 

	vector<string>::reference rval = vs[0];    // the same as value_type&
	cout << "vector<string>::reference: " << rval << endl;

	vector<string>::reverse_iterator vs_r_iteator_begin = vs.rbegin();
	cout << "vector<string>::reverse_iterator: " << *vs_r_iteator_begin << endl;

	cout << "output the data:" << endl;
	for(auto it = vs.begin(); it != vs.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "reverse iterator:" << endl;
	for(auto it = vs.rbegin(); it != vs.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "insert value:" << endl;
	vs.insert(vs.begin(), "ZZ");
	for(auto it = vs.begin(); it != vs.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "emplace value:" << endl;
	vs.emplace(vs.end(), "YY");   //emplace_front emplace_back
	vs.emplace_back("XX");
	for(auto it = vs.begin(); it != vs.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "erase first item:" << endl;
	vs.erase(vs.begin());
	for(auto it = vs.begin(); it != vs.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "push data to end:" << endl;
	vs.push_back("WW");
	for(auto it = vs.begin(); it != vs.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "swap data:" << endl;
	forward_list<double> fwd_swap{1.0, 2.0, 3.0};
	swap(fwd, fwd_swap);
	for(auto it = fwd_swap.begin(); it != fwd_swap.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "container  empty:" << endl;
	cout << "fwd.empty():"<<fwd.empty() << endl;

	cout << "container max size:" << endl;
	cout << "fwd.maxsize():" << fwd.max_size() << endl;

	cout << "contain seq constructor:" << endl;
	list<int> li1(5);
	for(auto it = li1.begin(); it != li1.end(); it++) {
		cout << *it <<" ";
	}
	cout << endl;

	list<int> li2(5,2);
	for(auto it = li2.begin(); it != li2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "seq container assign:" << endl;
	list<int> li3;
	li3.assign(li2.begin(),li2.end());
	li3.assign({1,2,3});
	li3.assign(3,5);

	for(auto it = li3.begin(); it != li3.end(); it++) {
		cout << *it <<" ";
	}
	cout << endl;

	return 0;
}

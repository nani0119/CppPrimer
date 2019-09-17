#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <list>
#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

void display_spilt()
{
	cout << "==============================================" << endl;
}

void print_dq(deque<int> &dq)
{
	for(auto it = dq.begin(); it != dq.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	// insert iterator
	// *it it++ ++it these operations exist, but do nothing to it. ecah operation return it
	deque<int> dq = {1,2,3,4};

	auto back_it = back_inserter(dq);
	back_it = 5;
	print_dq(dq);

	fill_n(back_inserter(dq), 4, 5);
	print_dq(dq);

	fill_n(front_inserter(dq), 4, 1);
	print_dq(dq);

	auto insert_it = inserter(dq, dq.begin());  // behaves the same as:
												// it = c.insert(it, val); // it points to the newly added element
												// ++it; // increment it so that it denotes the same element as before
	
	insert_it = 0;

	print_dq(dq);

	display_spilt();

	list<int> lst = {1,2,3,4};
	list<int> lst2, lst3; // empty lists

	copy(lst.begin(), lst.end(), front_inserter(lst2));   // 1st2 contains 4 3 2 1
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));  // after copy completes, 1st3 contains 1 2 3 4, iterator pos does not change
	display_spilt();

	// stream iterator
	
	vector<int> vi1;
	istream_iterator<int> is(cin), eof;
	while(is != eof)
	{
		vi1.push_back(*is);
		++is;
	}

	for(auto it = vi1.begin(); it != vi1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	display_spilt();
	
	istringstream iss("asdfsd 11111 333333");
	istream_iterator<string> is_s(iss), is_s_eof;
	vector<string> vi2(is_s, is_s_eof);
	for(auto it = vi2.begin(); it != vi2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	display_spilt();

	istringstream iss1("1111 2222 333");
	istream_iterator<string> is_s1(iss1), is_s1_eof;
	ostream_iterator<string> os_s1(cout, " ");
	copy(is_s1, is_s1_eof, os_s1);
	cout << endl;

	display_spilt();

	// istream_iterator<Sales_item> item_iter(cin), eof;
	// ostream_iterator<Sales_item> out_iter(cout, "\n");
	
	// reverse iterator
	vector<int> vi3 = {1,2,3,4,5,6,7,8,9};
	for(auto it = vi3.rbegin(); it != vi3.rend(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	display_spilt();


	string sr = "FIRST,MIDDLE,LAST";
	auto rcomma = find(sr.rbegin(), sr.rend(), ',');
	cout << string(sr.rbegin(), rcomma) << endl;
	cout << string(rcomma.base(), sr.end()) << endl;  // reverse_iterator.base() trans to normal 
	return 0;
}

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

void print_list(list<int>& lst)
{
	for(auto it = lst.begin(); it != lst.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void display_split()
{
	cout << "================================================" << endl;
}

int main(int argc, char *argv[])
{
	list<int> lst1 = {2,1,4,3,5};
	list<int> lst2 = {6,9,8,7,0};
	lst1.merge(lst2);

	print_list(lst1);
	display_split();

	lst1.remove(2);
	print_list(lst1);

	lst1.remove_if([](const int i){return (i%2) == 0;});
	print_list(lst1);

	lst1.reverse();
	print_list(lst1);
	display_split();

	lst1.sort();
	print_list(lst1);
	display_split();

	auto lst_it = back_inserter(lst1);
	lst_it = 9;

	lst1.unique();
	print_list(lst1);
	display_split();

	lst1.unique([](const int &i, const int& j){return i < j;});
	print_list(lst1);
	display_split();
	
	lst2 = {0,2,4,6,8};
	lst1.splice(lst1.end(), lst2);
	print_list(lst1);
	display_split();
	
	lst2 = {3,5,7,9};
	lst1.splice(lst1.begin(),lst2, ++(lst2.begin()), lst2.end());
	print_list(lst1);

	print_list(lst2);
	return 0;
}

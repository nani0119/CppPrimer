#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
#include <vector>
#include <list>

using namespace std;

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

void display_split()
{
	cout << "=============================================" << endl;
}
int main(int argc, char *argv[])
{
	cout << boolalpha;

	// accumulate
	vector<int> vec = {1,2,3,4,5,6,7,8,9};
	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << "accumulate num:" << sum << endl;
	display_split();

	vector<string> vecs= {"aa","bb","cc","dd"};
	string str_sum = accumulate(vecs.begin(), vecs.end(), string("."));
	cout << "accumulate str:" << str_sum << endl;
	display_split();

	// equal
	vector<string> vecs2 = {"aa", "bb","cc","dd","ee"};
	cout <<"equal:" << equal(vecs.begin(), vecs.end(), vecs2.begin())<< endl;

	display_split();

	// fill
	cout << "origin data: ";
	for(auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	fill(vec.begin(), vec.begin() + vec.size()/2, 10);

	cout << "fill after: ";
	for(auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "fill_n :";
	fill_n(vec.begin(), vec.size()/2, 5);
	for(auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	display_split();

	// back_inserter
	
	vec.clear();
	auto it = back_inserter(vec);
	*it = 42;

	fill_n(back_inserter(vec), 10, 1);

	cout << "back_inserter: ";
	for(auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	display_split();

	// copy
	cout << "copy:";
	vector<int> vec_c;
	auto ret = copy(vec.begin(), vec.end(), back_inserter(vec_c));
	for(auto it = vec_c.begin(); it != vec_c.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	display_split();

	cout << "replace:";
	replace(vec.begin(), vec.end(), 1, 2);  //replace 1 with 2
	for(auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	
	cout <<"replace_copy:";
	vec_c.clear();
	replace_copy(vec.begin(), vec.end(), back_inserter(vec_c), 2, 3);
	for(auto it = vec_c.begin(); it != vec_c.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	display_split();

	cout<< "Eliminating Duplicates" << endl;
	vector<string> vs1 = {"aaa","cc","aaa","cc","sd","sd","aaa","1234"};
	// sort words alphabetically so we can find the duplicates
	sort(vs1.begin(), vs1.end());

	// unique reorders the input range so that each word appears once in the
	// front portion of the range and returns an iterator one past the unique range
	auto end_unique = unique(vs1.begin(), vs1.end());
	vs1.erase(end_unique, vs1.end());
	// resort by length, maintaining alphabetical order among words of the same length
	stable_sort(vs1.begin(), vs1.end(), isShorter);
	for(auto it = vs1.begin(); it != vs1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	display_split();
	
	return 0;
}

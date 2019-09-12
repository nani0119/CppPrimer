#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
	vector<vector<string>> vec = {
									{"aa","bb","cc"}, 
									{"PP","QQ"},
									{"1","2"},
									{".",",","?"},
									{"\t","\n"},
								 };	
	for(auto it = vec.begin(); it != vec.end(); it++) {
		cout <<"size: " <<it->size() << endl;
		for(auto item = (*it).begin(); item != (*it).end(); item++) {
			cout << *item << " " ;
		}
		cout << endl;
	}
	cout << "==============================================" << endl;
	int a[] = {1,2,3,4,5,6,7};
	for(auto it =begin(a); it != end(a); it++) {
		cout << *it << " ";
	}
	cout << endl;
	cout << "==============================================" << endl;
	
	vector<int> iv(begin(a), end(a));
	for(auto it = iv.begin(); it != iv.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	string s = "abcdefgchiklmn";
	vector<char> cv(s.begin(), s.end());
	for(auto it = cv.begin(); it != cv.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;


	return 0;
}

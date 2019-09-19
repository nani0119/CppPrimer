#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>
#include "StrBlob.h"
#include "StrBlobPtr.h"
using namespace std;

int main(int argc, char *argv[])
{
	StrBlob b;
	StrBlobPtr bp(b);
	b.push_back("bbbbbbbb");
	b.push_back("aaaaaaaa");

	StrBlob b1 = b;  // copy construct


	StrBlob b2;
	b2 = b1;         // operator=

	StrBlob b3(b);   // copy construct

	b1.push_back("b1b1b1b1");
	b2.push_back("b2b2b2b2");
	b3.push_back("b3b3b3b3");

	vector<StrBlobPtr> vec = {b,b1,b2,b3};
	for(auto it = vec.begin(); it != vec.end(); it++) {
		auto item = *it;
		for(auto it_inner = item.begin(); it_inner != item.end(); it_inner++) {
			cout << *it_inner<<" ";
		}
		cout << endl;
	}
	return 0;
}

#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include "Sales_data.h"

bool compareIsbn(Sales_data& S1, Sales_data& S2)
{
	return S1.isbn() < S2.isbn();
}

int main(int argc, char* argv[])
{
#if 1
	Sales_data b1("234-987-2345",15, 20);
	//Sales_data b2(cin);
	Sales_data b2;
	cout << "input sales_data with format isbn units_sold price" << endl;
	cin >> b2;
	Sales_data bSum;

	//print(cout,b1);
	cout << "===============output=================" << endl;
	cout << b1 << endl;
    //bSum = add(b1,b2);
	bSum = b1 + b2;
    //print(cout, bSum);
	cout << bSum<< endl;

	cout << "b1 == b2: " << (b1 == b2? "true":"false")<< endl;
#else
	vector<Sales_data> svec;
	string isbn;
	string price;
	string count;
	while(cin >> isbn >> price >> count)
	{
		Sales_data S(isbn, stod(price), stod(count));
		svec.push_back(S);
	}
	//sort(svec.begin(), svec.end(), compareIsbn);
	sort(svec.begin(), svec.end(), [](Sales_data& S1, Sales_data& S2){return S1.isbn() < S2.isbn();});
	cout << "=============================" << endl;
	for(auto it = svec.begin(); it != svec.end(); it++)
	{
		cout << it->isbn() << endl;
	}
#endif
	return 0;
}

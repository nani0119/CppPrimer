#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	/* Defining and Initializing */
	vector<string> sv1;
	vector<string> sv2 = {"sv2","hello", "world"};
	vector<string> sv3{"sv3", "hello", "world"};
	// vector<string> sv4("sv4", "hello", "world");  //error
	vector<string> sv5 = sv2;
	vector<string> sv6(sv3);
	vector<string> sv7(3);
	vector<string> sv8(7, "hello");

	/* add element */
	vector<int> iv;
	for(auto i = 0; i < 10; i++)
		iv.push_back(i);

	vector<int>::size_type sz = iv.size();
	cout << "iv.size() "<< sz << endl
		<< "iv.empty() "<<(iv.empty()?"true":"false") << endl
		<< "iv[0] = " << iv[0] << endl;


	return 0;
}

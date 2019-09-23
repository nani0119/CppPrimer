#include <iostream>
#include <string>


using namespace std;


template <typename T, unsigned N>
unsigned size(const T (&a)[N])
{
	return N;
}


int main(int argc, char *argv[])
{
	char a[] = "aaaaaaaaaaaaaaaa";
	char b[] = "";
	int  c[] = {1,2,3,4};

	cout << "a size:" << size(a) << endl;
	cout << "b size:" << size(b) << endl;
	cout << "c size:" << size(c) << endl;
	return 0;
}

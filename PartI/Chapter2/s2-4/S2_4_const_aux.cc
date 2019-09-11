#include <iostream>

using namespace std;

const int local2file = 100;
extern const int constShared;
void print_var()
{
	cout << __FILE__ << ":const int local2file = " << local2file << endl;
	cout << __FILE__ << ":extern const int constShared = " << constShared << endl;
	return;
}

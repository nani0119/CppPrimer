#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(int argc, char *argv[])
{
	bitset<13> bitvec1(0xbeef); // bits are 1111011101111
	bitset<20> bitvec2(0xbeef); // bits are 00001011111011101111
	bitset<32> bitvec4("1100"); // bits 2 and 3 are 1, all others are 0

	string str("1111111000000011001101");
	bitset<32> bitvec5(str, 5, 4); // four bits starting at str[5], 1100
	bitset<32> bitvec6(str, str.size()-4); // use last four characters

	cout << boolalpha;
	cout << bitvec1.any() << endl;
	cout << bitvec1.count() << endl;
	cout << bitvec1.size() << endl;
	cout << bitvec5.test(0) << endl;
	cout << bitvec5.test(2) << endl;
	cout << bitvec5.set(2,false) << endl;
	cout << bitvec5.set() << endl;  // turn on all
	cout << bitvec5.reset(2) << endl;
	cout << bitvec5.reset() << endl;
	cout << bitvec5.flip(5) << endl;
	cout << bitvec5.flip() << endl;
	cout << bitvec5[5] << endl;
	cout << bitvec5.to_ullong() <<endl;
	cout << bitvec5.to_string() << endl; 
	cout << bitvec5.to_string('Z','N') << endl; 

	bitset<16> bitvec7;
	cin >> bitvec7;
	cout << bitvec7 << endl;
	return 0;
}

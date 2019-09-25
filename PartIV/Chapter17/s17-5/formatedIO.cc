#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

inline void split()  {cout << "===================================" << endl;}
int main(int argc, char *argv[])
{
	// bool value
	cout << "default bool values: " << true << " " << false << endl;
	cout << boolalpha;
	cout <<  "bool values: " << true << " " << false << endl;
	cout << noboolalpha;
	split();

	// the Base for Integral Values
	cout << uppercase;
	cout << showbase;
	cout << "default: " << 20 << " " << 1024 << endl;
	cout << "oct:" << oct << 20 << " " << 1024 << endl;
	cout << "hex:" << hex << 20 << " " << 1024 << endl;
	cout << "decimal:" << dec<< 20 << " " << 1024 << endl;
	cout << noshowbase;
	cout << nouppercase;
	split();

   	// Controlling the Format of Floating-Point Values
	cout << "Precision: " << cout.precision() << endl;
	cout << "value:" << sqrt(2.0) << endl;

	cout.precision(12);
	cout << "Precision: " << cout.precision() << endl;
	cout << "value:" << sqrt(2.0) << endl;

	cout << setprecision(6);
	cout << "Precision: " << cout.precision() << endl;
	cout << "value:" << sqrt(2.0) << endl;
	split();

	// the Notation of Floating-Point Numbers
	cout << "default format: " << 100 * sqrt(2.0) << endl;
	cout << "scientific:" << scientific << 100 * sqrt(2.0) << endl;
	cout << "fixed decimal:" << fixed << 100 * sqrt(2.0) << endl;
	cout << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << endl;
	cout << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << endl;
	split();

	// Printing the Decimal Point
	cout << "print 10:"<<10.0 << endl;
	cout << showpoint;
	cout << "print 10.0:" << 10.0 << endl; 
	cout << noshowpoint;
	
	split();
	// Padding the Output
	int i = -16;
	double d = 3.14159;

	// pad the first column to use a minimum of 12 positions in the output
	cout << "12 positions:" << endl;
	cout << "i: " << setw(12) << i << "next col" << endl;
	cout << "d: " << setw(12) << d << "next col" << endl;

	// left-justify
	cout << left;
	cout << "left-justify:" << endl;
	cout << "i: " << setw(12) << i << "next col" << endl;
	cout << "d: " << setw(12) << d << "next col" << endl;
	
	// right-justify
	cout << right;
	cout << "right-justify:" << endl;
	cout << "i: " << setw(12) << i << "next col" << endl;
	cout << "d: " << setw(12) << d << "next col" << endl;
	
	// internal 
	// internal controls placement of the sign on negative values 
	cout << internal;
	cout << "internal:" << endl; 
	cout << "i: " << setw(12) << i << "next col" << endl;
	cout << "d: " << setw(12) << d << "next col" << endl;

	// fill
	cout << "fill #" << endl;
	cout << setfill('#');
	cout << "i: " << setw(12) << i << "next col" <<endl;
	cout << "d: " << setw(12) << d << "next col" << endl;
	cout << setfill(' ');
	split();

	cout << right;
	return 0;
}

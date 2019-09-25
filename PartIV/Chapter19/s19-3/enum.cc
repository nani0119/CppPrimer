#include <iostream>
#include <string>

using namespace std;

// forward declaration of unscoped enum named intValues
enum intValues : unsigned long long; // unscoped, must specify a type

enum class open_mode {   // scoped enumeration
	input,
	output,
	append
};

enum color {    // unscoped enumeration
	red,
	yellow,
	green
};

enum class peppers      // scoped enumeration
{
	red, 
	yellow, 
	green
};

enum {                   // unnamed unscoped enumeration
	floatPrec = 6, 
	doublePrec = 10, 
	double_doublePrec =10
};


enum intValues : unsigned long long {
	charTyp = 255, 
	shortTyp = 65535, 
	intTyp = 65535,
	longTyp = 4294967295UL,
	long_longTyp = 18446744073709551615ULL
};

int main(int argc, char *argv[])
{
	color eyes = green; // ok: enumerators are in scope for an unscoped enumeration	
	// peppers p = green;  // error: enumerators from peppers are not in scope 
						// color::green is in scope but has the wrong type

	color hair = color::red; // ok: we can explicitly access the enumerators
	peppers p2 = peppers::red; // ok: using red from peppers

	int i = color::red; // ok: unscoped enumerator implicitly converted to int
	// int j = peppers::red; // error: scoped enumerations are not implicitly converted
	return 0;
}

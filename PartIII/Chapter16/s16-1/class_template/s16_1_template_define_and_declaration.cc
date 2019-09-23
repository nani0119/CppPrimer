#include <iostream>


extern template Blob<string> ;   // declaration
template Blob<string>            // define, all members is  instanted

extern template void compare(const string& s2, const string& s1);  // declaration
template void compare(const string& s1, const string& s2); // define




int main(int argc, char *argv[])
{
	
	return 0;
}

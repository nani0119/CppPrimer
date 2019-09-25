#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	ostringstream writeStr;
	ostringstream::pos_type marker = writeStr.tellp();
	cout <<"pos:" << marker << endl;
	writeStr << "1234567890";
	marker = writeStr.tellp();
	cout << "pos:" << marker << endl; 
	writeStr.seekp(3,ostringstream::beg);
	marker = writeStr.tellp();
	cout << "pos:" << marker << endl; 
	cout << writeStr.str() << endl;
	return 0;
}

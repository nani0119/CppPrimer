#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <exception>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[])
{
	string s1 = "aaaaaaaaa";
	string s2 = "bbbbbbbbb";
	try
	{
		if(s1 != s2)
		{
			throw runtime_error("string s1 != string s2");
		}
		cout << "string s1 == string s2" << endl;
	}
	catch(runtime_error err)
	{
		cout << err.what() << endl;
	}
	cout << "finish" << endl;
	return 0;
}

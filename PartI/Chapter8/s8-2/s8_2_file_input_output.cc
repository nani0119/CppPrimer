#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	// ifstream in("s8_2_input_file");	
	string file_name = "s8_2_input_file";
	ifstream in;
	in.open(file_name,ifstream::in);

	// ofstream out("s8_2_input_file"+".copy",ofstream::out);
	ofstream out;
	out.open(file_name + ".copy",ofstream::out|ofstream::trunc);
	// in            open for input
	// out           open for output
	// trunc         truncate the file
	// app           seek to the end before every write
	// ate           seek to the end immediately after the open
	// binary        Do IO in binary mode
	string s;	
	if (out)
	{
		while(getline(in, s))
		{
		    // ostringstream oss(s);
			ostringstream oss;
			oss << s;
			cout << oss.str() << endl;
			// istringstream iss(s);
			out << s << endl;
		}
	}
	else
	{
		cout << "open file fail" << endl;
		in.close();
		return 0;
	}
	in.close();
	out.close();

	cout <<boolalpha<<"out.is_open():"<< out.is_open()<<noboolalpha << endl;
	return 0;
}

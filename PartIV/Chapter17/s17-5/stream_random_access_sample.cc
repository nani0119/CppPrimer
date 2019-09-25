#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	// open for input and output and preposition file pointers to end-of-file
	fstream inOut("copyOut", fstream::ate | fstream::in |fstream::out);
	if (!inOut) 
	{
		cerr << "Unable to open file:copyOut, please creat a file named copyOut" << endl;
		return EXIT_FAILURE;
	}

	// inOut is opened in ate mode, so it starts out positioned at the end
	auto end_mark = inOut.tellg();  // remember original end-of-file position
	inOut.seekg(0, fstream::beg); // reposition to the start of the file
	size_t cnt = 0; // accumulator for the byte count
	string line; // hold each line of input

	// while we haven't hit an error and are still reading the original data
	while (inOut && inOut.tellg() != end_mark && getline(inOut, line)) 
	{
		cnt += line.size() + 1; // add 1 to account for the newline
		auto mark = inOut.tellg(); // remember the read position
		inOut.seekp(0, fstream::end); // set the write marker to the end
		inOut << cnt;
		if (mark != end_mark)
		{ 
			inOut << " ";
		}
		inOut.seekg(mark);
	}
	inOut.seekp(0, fstream::end); // seek to the end
	inOut << "\n"; // write a newline at end-offile

	return 0;
}

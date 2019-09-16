#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	auto old_state = cin.rdstate();
	cout << "input a string" << endl;
	cin >> s;

	cout << boolalpha;
	cout <<"s.eof():" <<cin.eof() << endl
		<< "s.fail():" <<cin.fail() << endl
		<< "s.bad():"  <<cin.bad() <<endl
		<< "s.good():" <<cin.good() << endl;
	cout << noboolalpha;
	cin.clear(iostream::eofbit);
	cin.setstate(iostream::eofbit);
	cin.setstate(old_state);
    cin.clear();

	cout << "============================================="<<endl;
	istringstream iss("abcd cccc");
	string str;
	while(iss >> str)
		cout << str << endl;

    cout << "============================================="<<endl;
	cout << "input strings ,quit with ctrl-d"<<endl;
	ostringstream oss;
	while(cin >> str)
		oss << str;
	cout << oss.str() << endl;

	cout << "============================================="<<endl;
	ifstream fin("s8_1_2_in_file");
	int a, b, c;
	while(getline(fin, str))
	{
		istringstream is(str);
		is >> a >> b >> c;
		cout << a <<" "<< b<<" "<< c << endl;
	}
	cout << "============================================="<<endl;
	cout << "hi!" << endl; // writes hi and a newline, then flushes the buffer
	cout << "hi!" << flush; // writes hi, then flushes the buffer; adds no data
	cout << "hi!" << ends; // writes hi and a null, then flushes the buffer

	cout << unitbuf; // all writes will be flushed immediately
	// any output is flushed immediately, no buffering
	cout << "hi!";
	cout << nounitbuf; // returns to normal buffering
	cout << endl;
	cout << "==============================================" << endl;
	//When an input stream is tied to an output stream, any attempt to read the input
    //stream will first flush the buffer associated with the output stream
	
	cin.tie(&cout); // illustration only: the library ties cin and cout for us
	// old_tie points to the stream (if any) currently tied to cin
	ostream *old_tie = cin.tie(nullptr); // cin is no longer tied
	// ties cin and cerr; not a good idea because cin should be tied to cout
	cin.tie(&cerr); // reading cin flushes cerr, not cout
	cin.tie(old_tie); // reestablish normal tie between cin and cout
	return 0;
}

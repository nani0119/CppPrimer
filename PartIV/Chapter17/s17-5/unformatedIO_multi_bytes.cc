#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

inline void split() {cout << "===========================" << endl;}
int main(int argc, char *argv[])
{
	const int sz = 8;
	char ch[sz];

	cin.get(ch, sz, ';');
	cout <<"out:"<< ch << endl;
	cin.get();
	cin.clear();
	split();

	cin.getline(ch, sz, ';');
	cout << "out:"<<ch << endl;
	cout << "count:" << cin.gcount() << endl;
	cin.clear();
	split();

	cin.read(ch,sz);
	cout <<"out:"<< ch << endl;
	
	cout << "count:" << cin.gcount() << endl;
	cin.clear();
	split();
	
	string s;
	cin.ignore(8,';');
	cin >> s;
	cout << s << endl;
	cin.clear();
	split();

	cout.write(ch, 4);
	cout<< endl;
	split();

	return 0;
}

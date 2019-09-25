#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

inline void split(){cout << "====================================" << endl;}

int main(int argc, char *argv[])
{

	// Single-Byte Operations
	cout << "Single-Byte Operations: getch/putch" << endl;
	char ch;
	while(cin.get(ch))
		cout.put(ch);
	
	cin.clear();
	split();

	// get byte as int value
	cout << "get byte form cin as int value" << endl;
	int i = 0;
	while((i = cin.get()) != EOF)
	{
		cout << i << " ";
		cout.put(i);
		cout << endl;
	}
	cin.clear();
	split();

	// Putting Back onto an Input Stream

	// putback
	string s;	
	cin.putback('>').putback('-').putback('-');
	cin >> s;
	cout << s << endl;
	cin.clear();
	split();

	cin.putback('a');
	cin.get(ch);
	cout.put(ch);
	cout << endl;
	cin.clear();
	split();

	// unget
	cout << "cin unget" << endl;
	cin.get(ch);
	cout << endl;
	cout.put(ch);
	cout << endl;
	cin.unget();
	cout << cin.get() << endl;
	cin.clear();
	split();
	
	cout << "set input stream:" << endl;
	cin;
	cin.get();
	cin >> s;
	cout << s <<endl;
	cout << "unget:" << endl;
	cin.unget();
	cin >> s;
	cout << s << endl;
	cin.clear();
	split();
#if 0
	cout << "loop , not stop:" << endl; 
	while((i = cin.get()) != EOF)
	{
		cout << i << " ";
		cin.unget();
	}

	cin.clear();
	split();
#endif

	// peek
	cout << "peek" << endl;
	cin;
	cout << cin.peek() << endl;
	cout << cin.peek() << endl;
	cin >> s;
	cout << s << endl;
	return 0;
}

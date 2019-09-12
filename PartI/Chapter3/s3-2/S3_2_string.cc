#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
	/* Defining and Initializing */
	string s1;
	string s2 = "s2 hello world";
	string s3 = s2;
	string s4("s4 hello world");
	string s5 = {"s5 hello world"};
	string s6 = string("s6 hello world");
	string s7(10,'a');
	
	cout << "s1 = " << s1 << endl
		 << "s2 = " << s2 << endl
		 << "s3 = " << s3 << endl
		 << "s4 = " << s4 << endl
		 << "s5 = " << s5 << endl
		 << "s6 = " << s6 << endl
		 << "s7 = " << s7 << endl;
	/* string operation */	
	cout << "==========================================" << endl;
	cout << "use getline for inputing string for s1, ctl-d quit" << endl;
	while(getline(cin, s1))
	{
		cout << "s1 = " << s1 << endl;
	}
	cout << "==========================================" << endl;
	cout << "use cin for inputing string for s1, ctl-d quit" << endl;
	cin.clear();
	while(cin >> s1)
	{
		cout << "s1 = " << s1 << endl;
	}
	cout << "==========================================" << endl;
	
	if(!s1.empty())
	{
		for (int i = 0; i < s1.size(); ++i) {
			cout << s1[i] << "  " << endl;
		}
	}
	cout << "==========================================" << endl;
	cout << "s1 == s2: "<<(s1 == s2? "true": "false") << endl;
	
	cout << "==========================================" << endl;
	cout << "s1 > s2: "<<(s1 > s2? "true": "false") << endl;
	
	cout << "==========================================" << endl;
	cout << "s1 + s2 = " << s1 + s2 << endl;
	
	cout << "==========================================" << endl;
	/* Dealing with the Characters in a string */
	cout << boolalpha;
	string str = "aA1\t, ";
	for (auto c : str) {
		cout <<"char:" <<c << endl
			 << "isalnum(c):" << (isalnum(c) != 0) << endl
			 << "isalpha(c):" << (isalpha(c) != 0) << endl
			 << "iscntrl(c):" << (iscntrl(c) != 0) << endl
			 << "isdigit(c):" << (isdigit(c) != 0) << endl
			 << "isgraph(c):" << (isgraph(c) != 0) << endl
			 << "islower(c):"<<  (islower(c) != 0) << endl
			 << "isupper(c):" << (isupper(c) != 0) << endl
			 << "isspace(c):" << (isspace(c) != 0) << endl
			 << "ispunct(c):" << (ispunct(c) != 0) << endl
			 << "isprint(c):" << (isprint(c) != 0) << endl
			 << "isxdigit(c):" << (isxdigit(c)!= 0) << endl;
		cout << "===========================================" << endl;
	}
	cout << noboolalpha;
   cout << "============================================" << endl;
	str = "aaaaa,.BBBBBB";
	cout <<"before:"<< str << endl;
	for (auto& c : str) {
		if(islower(c))
			c = toupper(c);
		else
			c = tolower(c);
	}
	cout << "after:" << str << endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	// construct string

	string str = "1234567890";
	cout << str << endl;

	string s1(str, 3);    //copy from pos 3 to end;
	cout << s1 << endl;

	string s2(str, 3, 5);  // copy from pos 3, len 5
	cout << s2 << endl;

	char ch[10] = {'1','2','3','4','5','6','7','8','9','0'};
	string s3(ch, 3);   // ch array, copy first 3 elements
	cout << s3 << endl;

	cout << "=================================================="<< endl;

	// substr
	
	string s4 = str.substr();
	cout << s4 << endl;

	string s5 = str.substr(3);
	cout << s5 << endl;

	string s6 = str.substr(3,4);
	cout << s6 << endl;

	cout << "==================================================" << endl;

	// change a string
	string s7 = "234567";
	auto s8 = s7.insert(s7.size(),"8");
	cout << s7 << endl;
	cout << s8 << endl;

	cout << s7.erase(4, 4) << endl;

	cout << s7.assign("890") << endl;

	cout << s7.append("321") << endl;

	cout << s7.replace(0,1,"11") << endl;
	cout << s7.replace(s7.begin(), s7.end(), "0") << endl;

	cout << "=================================================" << endl;

	// search
	str = "0123456789";
	cout << str << endl;
	cout << str.find("3", 1)<<endl;
	cout << str.rfind("3",4) << endl;

	str = "112233445566778899";
	cout << str.find_first_of("6",0,15) << endl;
	cout << str.find_last_of("6") << endl;
	cout << str.find_first_not_of("6",2,8) << endl;
	cout << str.find_last_not_of("6") << endl;


	cout << "=================================================" << endl;

	cout << to_string(324.0) << endl;
	cout << stoi("123") << endl;
	cout << stod("123") << endl;
	cout << stoul("123") << endl;
	return 0;
}

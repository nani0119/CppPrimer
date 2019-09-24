#include <iostream>
#include <regex>
#include <string>


using namespace std;

int main(int argc, char *argv[])
{
	string fmt = "$2.$5.$7";
	string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	// 1. (\\()? an optional open parenthesis for the area code
	// 2. (\\d{3}) the area code
	// 3. (\\))? an optional close parenthesis for the area code
	// 4. ([-. ])? an optional separator after the area code
	// 5. (\\d{3}) the next three digits of the number
	// 6. ([-. ])? another optional separator
	// 7. (\\d{4}) the final four digits of the number
	regex r(pattern);
	string s;
	while (getline(cin, s))
	{
		cout <<"output:"<< regex_replace(s, r, fmt, regex_constants::format_no_copy) << endl;
	}
	return 0;
}

#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool vaild(const smatch& m)
{
	if(m[1].matched)
	{
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else
	{
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

int main(int argc, char *argv[])
{
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
	try{
		while(getline(cin,s))
		{
			sregex_iterator it(s.begin(), s.end(),r), end_it;
			if(it != end_it)
			{
				while(it != end_it)
				{
					if(vaild(*it))
					{
						cout << "vaild:" << it->str() << endl;
					}
					else
					{
						cout << "invaild phone number" << endl;
					}
					++it;
				}
			}
			else
			{
				cout << "not found phone number" << endl;
			}
		}
	}
	catch (regex_error e)
	{
		cout << e.what() << "\n code:" << e.code() << endl;
	}
	return 0;
}

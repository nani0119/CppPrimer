#include <iostream>
#include <string>
#include <vector>

namespace nsp {

	using namespace std;
	int func()
	{
		string s = "aaaaaa";
		cout << s << endl;
		return 0;
	}

}

namespace ns {
	using namespace std;
	int func()
	{
		string s = "aaaaaa";
		cout << s << endl;
		return 1;
	}
	namespace n{
		int func()
		{
			string s = "aaaaaa";
			cout << s << endl;
			return 1;
		}
	}
}

int main(int argc, char *argv[])
{
	nsp::func();
	ns::func();
	ns::n::func();
	// ns::std::string a = "bbbbbbb"; //error
	std::string b = "ccccccc";
	std::cout << b << std::endl;
	return 0;
}

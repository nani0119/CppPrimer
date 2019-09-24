#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char *argv[])
{
	string pattern = "[^c]ei";
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;
	string test_str = "receipt freind theif receive";

	if(regex_search(test_str,results,r))
		cout << results.str() << endl;


	//==============================================
	regex r1;
	r1 = "[^c]ei";
	r1 = r;
	cout << r1.mark_count() << endl;
	cout << r1.flags()<<endl;
	//=============================================
	regex r2("[[:alnum:]]+\\.(cpp|cxx|cc)$",regex::icase);
	cout << r2.mark_count()<< endl;
	smatch ret;
	string filename;
	while(cin >> filename)
	{
		if(regex_search(filename,ret,r2))
			cout<<"filename:" << ret.str()<<endl;
	}
	// ===========================================

	try
	{
		regex r3("[[:alnum:]+\\.(cpp|cxx|cc)$",regex::icase);
	}
	catch (regex_error e)
	{
		cout <<"msg:" <<e.what() << endl;
		cout << "code:"<<e.code() << endl;
	}

	// =========================================
	
	cmatch cret;
	if(regex_search("file.cc",cret,r2))
		cout << cret.str() << endl;

	// ========================================
	
	regex r4(pattern,regex::icase);
	sregex_iterator it(test_str.begin(), test_str.end(),r4);
	sregex_iterator end_it;
	while(it != end_it)
	{
		cout << it->str() << endl;
		++it;
	}
	return 0;
}

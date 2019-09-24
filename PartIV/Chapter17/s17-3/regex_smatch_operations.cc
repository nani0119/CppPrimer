#include <iostream>
#include <regex>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
	try{

		string pattern = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
		regex r(pattern, regex::icase);
		// smatch results;
		string test_str = "phone NO.:(111)-222-3333 xdfsdfesdf 444-555-7777";
		// regex_search(test_str,results,r);
		for(sregex_iterator it(test_str.begin(), test_str.end(),r),end_it; it != end_it; it++){
			cout << "====================================" << endl;
			auto results = *it;
			cout << "results.ready():" << (results.ready()?"true":"false") << endl;
			cout << "results.size(): " << results.size() << endl; 
			cout << "results.prefix():" << results.prefix() << endl;
			cout << "results.str():" << results.str() << endl;
			cout << "results.suffix():" << results.suffix() << endl;
			cout << "results.str(0):" << results.str(0) << endl;
			cout << "results.lenght[0]:" << results.length(0) << endl;
			cout << "results.str(1):" << results.str(1) << endl;
			cout << "results.lenght[1]:" << results.length(1) << endl;
			cout << "results.position(1):" << results.position(1)<<endl;

			auto ssub_match_obj = results[2];
			cout << "ssub_match: ssub_match = results[2]" << endl;
			cout << "ssub_match_obj.str():" << ssub_match_obj.str() << endl;
			cout << "ssub_match_obj.length():" << ssub_match_obj.length() << endl;
			string s = ssub_match_obj;
			cout << "string s = ssub_match_obj:" << s <<endl;
			cout << "ssub_match_obj iterator:" << endl;
			for(auto it = ssub_match_obj.first; it != ssub_match_obj.second; it++) {
				cout << *it << endl;
				
			}
		}
	}

	catch (regex_error e)
	{
		cout << e.what() << "\n code:" << e.code() << endl;
	}
	return 0;
}

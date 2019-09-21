#include <fstream>
#include <iostream>
#include <string>
#include "common.h"
#include "QueryExpression.h"
using namespace std;

class QueryExpression;
void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	while(true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		getline(cin, s);
		if(!cin || s == "q")
			break;
		// string temp = deletAllSpace(s);
		QueryExpression  express(s);
		Query q = express.calcQueryResult();
		print(cout, q.eval(tq));
		// cout << q.rep() << endl;
	}
	return;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "prog file (~ | &)" << endl;
		return 1;
	}
	ifstream infile(argv[1]);
	runQueries(infile);
	return 0;
}

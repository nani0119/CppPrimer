#include <fstream>
#include <iostream>
#include <string>
#include "QueryResult.h"
#include "TextQuery.h"

using namespace std;

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	tq.debug();
	while(true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		if(!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s));
	}
	return;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "prog file" << endl;
		return 1;
	}
	ifstream infile(argv[1]);
	runQueries(infile);
	return 0;
}

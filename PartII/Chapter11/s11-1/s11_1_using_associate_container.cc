#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>


using namespace std;

void count_word()
{
	set<string> exclude = {"the","The","a", "A", "an", "An"};
	map<string, size_t> word_count;
	ostream_iterator<string> out(cout);
	out = "input words:\n";
	istream_iterator<string> in(cin), eof;
	while(in != eof)
	{
		if(exclude.find(*in) == exclude.end())
		{
			word_count[*in]++;
		}
		in++;
	}
	fill_n(out, 10, "=");
	out = "\n";
	for(auto &w: word_count)
	{
		out =  w.first ;
		out = ": ";
	    out = to_string(w.second);
	    out =  "\n";
	}
	return; 
}

int main(int argc, char *argv[])
{
	count_word();
	return 0;
}

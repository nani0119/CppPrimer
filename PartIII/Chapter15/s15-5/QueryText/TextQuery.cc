#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream& is):file(new vector<string>)
{
	string text;
	while(getline(is,text))
	{
		file->push_back(text);
		auto n = file->size() - 1; //line number
		transform(begin(text), end(text), begin(text), [](char c){return (!ispunct(c)? c: ' ');});  //replace punct for space
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto& lines = wm[word];
			if (!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& sougth) const
{

#if DEBUG
	cout << "TextQuery query:" << sougth << endl;
#endif
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sougth);
	if (loc == wm.end())
		return QueryResult(sougth, nodata, file);
	else
		return QueryResult(sougth, loc->second, file);
}

#ifdef DEBUG
void TextQuery::debug()
{
	cout << "===================text content=======================" << endl;
	for(auto it = file->begin(); it != file->end(); it++) {
		cout << *it << endl;
	}
	cout << "====================map content=======================" << endl;
	for(auto it = wm.begin(); it != wm.end(); it++) {
		cout << it->first << ":";
		for(auto sit = it->second->begin(); sit != it->second->end(); sit++) {
			cout << *sit << " ";	
		}
		cout << endl;
	}
}
#else
void TextQuery::debug()
{
	return;
}
#endif

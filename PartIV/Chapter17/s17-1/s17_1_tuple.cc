#include <iostream>
#include <string>
#include <vector>
#include <tuple>


using namespace std;

int main(int argc, char *argv[])
{
	tuple<int,string,vector<string>,vector<int>> t1(
													1,
													"string",
													{"111","2222","3333"},
													{1,2,3}
													);

	tuple<int,string,vector<string>,vector<int>> t2 = make_tuple(1,"string",vector<string>({"111","222","333"}),vector<int>({1,2,3}));
	size_t sz = tuple_size<decltype(t1)>::value;
	cout << sz << endl;

	tuple_element<2,decltype(t1)>::type vec_str = get<2>(t1);
	for(auto it = vec_str.begin(); it != vec_str.end(); it++) {
		cout << *it << endl;
	}

	 get<0>(t1) *= 2;
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;


template <typename T>
using twin = pair<T,T>;

template <typename T>
using twin_u = pair<T, string>;

int main(int argc, char *argv[])
{
	twin<string> pt("1","1");

	twin_u<int> ps(1,"s");
	return 0;
}

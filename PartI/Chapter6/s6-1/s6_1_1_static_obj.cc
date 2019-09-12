#include <iostream>
#include <string>

using namespace std;

int count_calls()
{
	static size_t ctr = 0;  // once
	return ++ctr;           // persist
}


int main(int argc, char *argv[])
{
	for (auto i = 0; i < 10; ++i) {
		cout << count_calls() << " ";
	}
	cout << endl;
	return 0;
}

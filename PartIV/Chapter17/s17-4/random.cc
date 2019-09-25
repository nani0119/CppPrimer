#include <iostream>
#include <random>
#include <string>
#include <ctime>
using namespace std;

int random_test()
{
	static default_random_engine e(time(0));
	static uniform_int_distribution<int> u(0,9);
	for (int i = 0; i < 10; ++i) {
		cout << u(e) << " ";
	}
	cout << endl;
	return 0;
}


int main(int argc, char *argv[])
{
	random_test();
	random_test();
	return 0;
}

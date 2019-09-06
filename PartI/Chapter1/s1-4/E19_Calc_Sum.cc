#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int i = 50;
	int sum = 0;
	cout << "output the sum from 50 to 100: ";
	while (i < 101){
		sum += i;
		i++;
	}
	cout << sum << endl;
	return 0;
}

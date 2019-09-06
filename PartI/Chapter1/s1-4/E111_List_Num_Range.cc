#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int first = 0, second = 0;
	int i = 0;
	cout << "input two integer,print each numbers between 1st and 2nd" << endl;

	cin >> first >> second;
	while(first <= second)
	{
		if(((i % 8) == 0)&& i != 0)
		{
			cout << endl;
		}
		cout << first << " ";
		i++;
		first++;
	}
	cout << endl;
	return 0;
}

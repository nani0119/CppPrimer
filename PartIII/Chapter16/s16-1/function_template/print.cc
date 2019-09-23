#include <iostream>
#include <string>


using namespace std;

template <typename T, unsigned N>
void print(const T (&a)[N])
{
	unsigned i = 0;
	while(i < N)
	{
		cout << a[i] << " ";
		i++;
	}
	cout << endl;
}


int main(int argc, char *argv[])
{
	int a[5] = {1,2,3,4,5};
	print(a);
	print("hello world");
	return 0;
}

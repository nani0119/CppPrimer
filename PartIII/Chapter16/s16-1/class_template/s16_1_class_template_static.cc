#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Foo
{
private:
		static std::size_t ctr;
public:
		Foo()
		{
			++ctr;
		}
		static std::size_t count()
		{
			return ctr;
		}
};

template <typename T>
size_t Foo<T>::ctr = 0;

int main(int argc, char *argv[])
{
	Foo<int> fi1;
	cout << fi1.count() << endl;
	Foo<int> fi2;
	cout << fi2.count() << endl;

	Foo<string> fs;
	cout << fs.count() << endl;
	
	return 0;
}

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class debugDelete
{
private:
	ostream& os;
public:
	debugDelete(ostream& s = cerr): os(s) {}

	template <typename T>
	void operator()(T* p)
	{
		cout << "delete pointer:" << p <<endl;
		delete p;
	}
};


int main(int argc, char *argv[])
{
	int* pi = new int(42);
	debugDelete d(cout);
	d(pi);

	double * pd = new double;
	debugDelete()(pd);

	unique_ptr<string, debugDelete> us(new string, debugDelete());
	return 0;
}

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "signed convert to unsigned"<<endl;
	int i = -42;
	unsigned u = 10;
	cout << "i = " << i << " " << "u = " << u << endl;
	cout << "i + u = " << i + u << endl;
	cout << "=========================================" << endl;

	cout << "wrap around" << endl;
	unsigned u1 = 42, u2 = 10;
	cout << "unsigned u1 = 42, u2 = 10" << endl;
	cout << "u1 - u2 =" << u1 - u2 <<endl;
    cout << "u2 - u1 ="	<< u2 -u1 << endl;

	cout << "=========================================" << endl;
	cout <<"can never be less than 0; the condition will always succeed" << endl;
	cout << "for (unsigned u = 10; u >= 0; --u)" << endl
		<<"\tstd::cout << u << std::endl;" << endl;
	
	cout << "=========================================" << endl;
	cout << "Escape Sequences"<<endl;
	cout <<"\\4dO\\115 = " << "\x4dO\115" << endl;
	cout << "=========================================" << endl;
	return 0;
}

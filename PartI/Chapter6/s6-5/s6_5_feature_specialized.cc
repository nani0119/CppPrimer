#include <iostream>
#include <string>
//#define NDEBUG   //close assert
#include <cassert>
using namespace std;

// =============================================
// default args

void default_args(size_t sz = 0)
{
	cout << sz << endl;
}

// =============================================
constexpr int new_sz() { return 42; }

// ============================================
// debug
void debug()
{
	cout << __FILE__ << endl
	    << __LINE__ << endl
		<< __TIME__ << endl
	    << __DATE__ << endl
		<< __func__ << endl;	
}


int main(int argc, char *argv[])
{
	default_args();
	default_args(5);
	cout << "========================================" << endl;
	constexpr int foo = new_sz(); // ok: foo is a constant expression
	cout << foo << endl;
	cout << "========================================" << endl;

	debug();

	assert(1 > 2);
	return 0;
}

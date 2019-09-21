#include "Window_mgr.h"

int main(int argc, char* argv[])
{
	Screen myScreen(5, 10, 'X');
	myScreen.move(3, 2).set('#').display(cout);
	cout << endl;
	cout << "=================================" << endl;
	myScreen.display(cout);
	cout << endl;
	return 0;
}

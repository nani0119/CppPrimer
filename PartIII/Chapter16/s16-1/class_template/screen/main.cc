#include "screen.h"


int main(int argc, char *argv[])
{
	screen<string,80,16> s = {"aa","bb","cc"};
	s.show();

	screen<int, 1,2> si = {1,2,3};
	si.show();
	return 0;
}

#include <iostream>

using namespace std;


// classes prevented copies by declaring their copy constructor
// and copy-assignment operator as private
// However, friends and members of the class can still make copies. 
// To prevent copies by friends and members, we declare
//these members as private but do not define them

void class_copy();
class PrivateCopy
{
	friend void class_copy();
private:
	
	// copy construct
	PrivateCopy(const PrivateCopy& c);
	//copy assignment
	PrivateCopy& operator=(const PrivateCopy& c);
public:
	PrivateCopy(){};
	virtual ~PrivateCopy(){};
};


void class_copy()
{
	PrivateCopy p1;
	// PrivateCopy p2 =p1;  // these members as private but do not define them
}

int main(int argc, char *argv[])
{
	PrivateCopy p1;
	// PrivateCopy p2 = p1; // can not copy
	return 0;
}

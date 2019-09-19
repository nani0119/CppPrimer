#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

void process(shared_ptr<int> spi)
{
	cout << "process finish" << endl;
}

int main(int argc, char *argv[])
{
	
	// Don’t Mix Ordinary Pointers and Smart Pointers
	int* new_i = new int(42);
	process(shared_ptr<int>(new_i));  // error, the memery by new is deleted, when process finish
	int j = *new_i;
	cout << j << endl;

	// auto sp_i = make_shared<int>(42); // ok
	shared_ptr<int> sp_i(new int(42));
	process(sp_i);
	j = *sp_i;
	cout << j << endl;

	// Don’t Use sp.get() to Initialize or Assign Another Smart Pointer
	shared_ptr<int> p(new int(42)); 
	int* q = p.get();  //ok: but don't use q in any way that might delete its pointer
	
	// new block
	{
		shared_ptr<int>(q);  // undefined: two independent shared_ptrs point to the same memory
	}  // the memery of q is deleted

	int foo = *p; // undefined; the memory to which p points was freed
	cout << foo << endl;
	
	// point to local var
	int i = 100;
	shared_ptr<int> pi(&i);  // delete local i,  exception

	return 0;
}

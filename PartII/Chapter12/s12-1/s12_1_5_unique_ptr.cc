#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

void deleter(string* s)
{
	cout <<*s << endl;
	delete s;
}

int main(int argc, char *argv[])
{
	unique_ptr<string> ups(new string("uuuuuuuuuuu"));
	cout << *ups << endl;
	string* ps = ups.release();  // ups is nullptr
	cout << *ps << endl;

	unique_ptr<string> ups1(new string("vvvvvvvvvvv"));
	unique_ptr<string> ups2;
	ups2.reset(ups1.release());
	cout << *ups2 << endl;

	ups2.reset(new string("wwwwwwwwwww"));
	cout << *ups2 << endl;
	ups2.reset();  // ups2 = nullptr or ups2.reset(nullptr)

	auto f = [](string* s){cout << *s << endl; delete s;};
	unique_ptr<string, decltype(f)> ups_del(new string("xxxxxxxxxxxxx"),f);

	unique_ptr<string, decltype(deleter)*> ups_f(new string("yyyyyyyyyyyyyy"),deleter);


	// unique_ptr provide the deleter for array , but shared_ptr not
	unique_ptr<int[]> u_array(new int[10]{1,2,3,4,5,6});
	cout <<"unique_ptr:" << u_array[0] << endl;
	u_array[0] += 1;
	cout <<"unique_ptr:" << u_array[0] << endl;
	u_array.release();

	shared_ptr<int[]> s_array(new int[10]{0,2,3,4,5}, [](int* arr){ cout << "delete array" << endl; delete [] arr;});
	cout << "shared_ptr:" << s_array[0] << endl;
	s_array[0] += 1;
	cout << "shared_ptr:" << s_array[0] << endl;
	s_array.reset();
	return 0;
}

#include <iostream>
#include <string>
#include <thread>

using namespace std;

void say_hello_world()
{
	cout << "hello world" << endl;
}


int main(int argc, char *argv[])
{
	thread t(say_hello_world);
	t.join();
	return 0;
}

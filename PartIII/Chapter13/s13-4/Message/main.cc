#include <iostream>
#include <string>
#include <vector>
#include "Message.h"
#include "Folder.h"

int main(int argc, char *argv[])
{
	
	vector<Message*> mv;
	vector<Folder*> fv;	

	Folder f1("f1");

	Message m1("m1");
	m1.save(f1);

	Message m2("m2");
	m2.save(f1);

	Message m3 = m2;
	m3.setContents("m3");
	
	Folder f2 = f1;
	f2.setName("f2");

	Folder f3;
	f3 = f1;
	f3.setName("f3");

	Message m4("m4");
	f3.addMsg(&m4);

	Message m5("m5");
	m5.save(f3);

	 m1.remove(f1);
	 f2.remMsg(&m2);

	 Folder f4("f4");
	 m1.save(f4);
	 Folder f5("f5");
	 f5 = std::move(f4);
	 f5.setName("f5");

	cout << "=======================Folder========================="<< endl;
	f1.printFolder();
	f2.printFolder();
	f3.printFolder();
	f5.printFolder();

	cout << "========================Message======================="<< endl;
	m1.printMessage();
	m2.printMessage();
	m3.printMessage();
	m4.printMessage();
	m5.printMessage();
	return 0;
}

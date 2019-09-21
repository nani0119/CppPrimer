#include <iostream>
#include <set>
#include <string>
#include "Message.h"
using namespace std;
class Folder;


void Message::add_to_folders(const Message& m)
{
	for(auto f : m.folders)
	{
		f->addMsg(this);
	}
}

void Message::remove_from_folders()
{
	for(auto f: folders)
	{
		f->remMsg(this);
	}
}

void Message::move_folders(Message *m)  // rvalue
{
	folders = std::move(m->folders);
	for(auto f: folders){
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

Message::Message(const Message& msg):contents(msg.contents), folders(msg.folders)
{
	add_to_folders(msg);
}
Message& Message::operator=(const Message& msg)
{
	Message temp = msg;
	remove_from_folders();
	contents = temp.contents;
	folders = temp.folders;
	add_to_folders(*this);
	return *this;
}

Message::Message(Message&& rmsg): contents(std::move(rmsg.contents))
{
	move_folders(&rmsg);
}

Message& Message::operator=(Message&& rmsg)
{
	if(this != &rmsg)
	{
		remove_from_folders();
		contents = std::move(rmsg.contents);
		move_folders(&rmsg);
	}
	return *this;
}
Message::~Message()
{
	remove_from_folders();
}
void Message::save(Folder& folder)
{
	folders.insert(&folder);
	folder.addMsg(this);
}
void Message::remove(Folder& folder)
{
	folders.erase(&folder);
	folder.remMsg(this);
}

void Message::addFolder(Folder* folder)
{
	auto ret = folders.find(folder);
	if(ret == folders.end())
	{
		folders.insert(folder);
		folder->addMsg(this);
	}
}

void Message::remFolder(Folder* folder)
{
	auto ret = folders.find(folder);
	if(ret != folders.end())
	{
		folders.erase(folder);
		folder->remMsg(this);
	}
}

string  Message::getContents()
{
	return contents;
}

void Message::setContents(string c)
{
	contents=c;
}

void Message::printMessage()
{
	cout << "message content:" << contents << endl;
	cout << "-------->" << endl;
	for(auto f: folders)
	{
		cout << f->getName() << endl;
	}
	cout << "<--------" << endl;
}

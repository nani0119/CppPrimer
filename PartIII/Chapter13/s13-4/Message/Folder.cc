#include <iostream>
#include <string>
#include "Folder.h"
using namespace std;

void Folder::add_to_messages(Folder& folder)
{
	for(auto m:folder.messages)
	{
		m->save(*this);
	}
}

void Folder::remove_from_messages()
{
	for(auto m:messages)
	{
		m->remove(*this);
	}
}

void Folder::move_messages(Folder* f)
{
	messages = std::move(f->messages);
	for(auto m: messages)
	{
		m->remFolder(f);
		m->addFolder(this);
	}
	f->messages.clear();
}

Folder::Folder(const Folder& folder)
{
	name = folder.name;
	messages = folder.messages;
	add_to_messages(*this);
}

Folder& Folder::operator=(const Folder& folder)
{
	Folder temp = folder;
	remove_from_messages();
	name = folder.name;
	messages = folder.messages;
	add_to_messages(*this);
	return *this;

}

Folder::Folder(Folder&& rf): name(std::move(rf.name))
{
	move_messages(&rf);
}

Folder& Folder::operator=(Folder&& f)
{
	if(this != &f)
	{
		remove_from_messages();
		name = std::move(f.name);
		move_messages(&f);
	}
	return *this;
}

Folder::~Folder()
{
	remove_from_messages();
}

void Folder::addMsg(Message* msg)
{
	auto ret = messages.find(msg);
	if (ret == messages.end())
	{
		messages.insert(msg);
		msg->addFolder(this);
	}
}

void Folder::remMsg(Message* msg)
{
	auto ret = messages.find(msg);
	if (ret != messages.end())
	{
		messages.erase(msg);
		msg->remFolder(this);
	}
}


string Folder::getName()
{
	return name;
}

void Folder::setName(string n)
{
	name = n;
}
void Folder::printFolder()
{
	cout << "Folder name:" << name << endl;
	cout << "--------->" << endl;
	for(auto m : messages)
	{
		cout << m->contents << endl;
	}
	cout << "<---------" << endl;
}

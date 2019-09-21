#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <string>
#include <set>
#include "Message.h"
using namespace std;

class Message;
class Folder{
	private:
		string name;
		set<Message*> messages;
		void add_to_messages(Folder& folder);
		void remove_from_messages();
		void move_messages(Folder* rf);
	public:
		Folder(string name = ""):name(name){};
        Folder(const Folder& folder);
		Folder& operator=(const Folder& folder);
		Folder(Folder&& rfolder);
		Folder& operator=(Folder&& folder);
		~Folder();
		void addMsg(Message* msg);
		void remMsg(Message* msg);
		string getName();
		void setName(string);
		void printFolder();
};
#endif

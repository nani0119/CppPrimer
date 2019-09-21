#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <set>
#include <string>
#include "Folder.h"

using namespace std;
class Folder;

class Message {
	friend class Folder;

	private:
		string contents;
		set<Folder*> folders;
		void add_to_folders(const Message& m);
		void remove_from_folders();
		void move_folders(Message* m);
	public:
		explicit Message(string msg = ""):contents(msg) {};
		Message(const Message& msg);
		Message& operator=(const Message& msg);
		Message(Message&& rmsg);
		Message& operator=(Message&& rmsg);
		~Message();
		void save(Folder& folder);
		void remove(Folder& folder);
		void addFolder(Folder* folder);
		void remFolder(Folder* folder);
		string getContents();
		void setContents(string contents);
		void printMessage();
};
#endif

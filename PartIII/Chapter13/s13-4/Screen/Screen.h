#ifndef SCREEN_HH
#define SCREEN_HH

#include <iostream>
#include <string>
using namespace std;

class Window_mgr;

class Screen
{
	friend class Window_mgr;
	public:
		typedef string::size_type pos;
		Screen() = default;
		Screen(pos ht, pos wd, char c);
		char get() const;
		inline char get(pos ht, pos wd) const;
		Screen& move(pos r, pos c);
		Screen& set(char ch);
		Screen& set(pos r, pos c, char ch);
		Screen& display(ostream& os);
		const Screen& display(ostream& os) const;
		pos getCursor() const;
	private:
	    pos cursor = 0;
		pos height = 0;
		pos width = 0;
		string contents;
		mutable size_t access_ctr;
		void do_display(ostream& os) const;
};

#endif

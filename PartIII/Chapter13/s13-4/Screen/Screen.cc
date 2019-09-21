#include "Screen.h"

Screen::Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht*wd, c)
{
}

char Screen::get() const
{
	access_ctr++;
	return contents[cursor];
}

char Screen::get(pos r, pos c) const
{
	pos row = width * r;
	return contents[row+c];
}

Screen& Screen::move(pos r, pos c)
{
	pos row = width * r;
	cursor = row + c;
	return *this;
}

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

Screen& Screen::set(pos r, pos c, char ch)
{
	pos row = width * r;
	contents[row + c] = ch;
	return *this;
}

void Screen::do_display(ostream& os) const
{
	for(decltype(height) r = 0; r < height; r++)
	{
		for(decltype(width) c = 0; c < width; c++)
		{	
			os << contents[r*width + c];
		}
		os << endl;
	}
}

Screen& Screen::display(ostream& os)
{
	do_display(os);
	return *this;
}

const Screen& Screen::display(ostream& os) const
{
	do_display(os);
	return *this;
}

Screen::pos Screen::getCursor() const
{
	return cursor;
}

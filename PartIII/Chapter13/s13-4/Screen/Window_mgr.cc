#include "Window_mgr.h"

void Window_mgr::clear(ScreenIndex index)
{
	Screen& s = screens[index];
	s.contents = string(s.height*s.width, ' ');
}


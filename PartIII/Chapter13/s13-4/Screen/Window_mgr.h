#ifndef WINDOWS_MGR_H
#define WINDOWS_MGR_H

#include <vector>
#include "Screen.h"


using namespace std;


class Window_mgr
{
	public:
		using ScreenIndex = vector<Screen>::size_type;
		void clear(ScreenIndex index);
	private:
		vector<Screen> screens{Screen(24, 80, ' ')};
};
#endif

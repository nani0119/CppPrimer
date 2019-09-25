#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
	string ScreenName;
	typedef std::string::size_type pos;

	Screen(string s):contents(s),cursor(0),height(0),width(0){}
	char get_cursor() const 
	{ 
		return contents[cursor]; 
	}
	char get() const
	{
		return contents[cursor];
	}
	char get(pos ht, pos wd) const
	{
		pos row = ht * width;
		return contents[row + wd];
	}
	

	// returns a pointer to member
	static const string Screen::* data()
	{
		return &Screen::contents;
	}
	


	// other interface and implementation members as before
	// Action is a pointer that can be assigned any of the cursor movement members
	using Action = Screen& (Screen::*)();

	enum Directions { HOME, FORWARD, BACK, UP, DOWN };

	// other interface and implementation members as before
	Screen& home() {cout << "action:home" << endl; return *this;} // cursor movement functions
	Screen& forward() {cout << "action:forward" << endl; return *this;};
	Screen& back() {cout << "action:back" << endl; return *this;}; 
	Screen& up(){cout << "action:up"<<endl; return *this;};
	Screen& down(){cout << "action:down"<<endl; return *this;};

	Screen& move(Directions cm)
	{
		return (this->*Menu[cm])();
	}
private:
	std::string contents;
	pos cursor;
	pos height, width;


	static Action Menu[]; // function table
};

// define and initialize the static table itself
Screen::Action Screen::Menu[] = { 
		&Screen::home,
		&Screen::forward,
		&Screen::back,
		&Screen::up,
		&Screen::down,
	};

int main(int argc, char *argv[])
{
	Screen myScreen("aaaaaaaa");
	Screen* pScreen = &myScreen;

	// pname can point to a string member of a const (or non const) Screen object
	string Screen::*pname;
	pname = &Screen::ScreenName;

	myScreen.*pname = "myScreen";
	//.* dereferences pdata to fetch the contents member from the object myScreen
	auto s = myScreen.*pname;
	// ->* dereferences pdata to fetch contents from the object to which pScreen points
	s = pScreen->*pname;

	cout <<"Screen name:"<< s << endl;

	// =====================================================================
	const string Screen::*pdata;
	pdata = Screen::data();

	auto content = myScreen.*pdata;
	cout << "Screen content:" << content << endl;

	//=====================================================================
	// pmf is a pointer that can point to a Screen member function that is const
	// that returns a char and takes no arguments
	auto pmf = &Screen::get_cursor;   // must explicitly use the address-of operator

	char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
	pmf2 = &Screen::get;  // must explicitly use the address-of operator


	char c1 = (pScreen->*pmf)();
	cout << c1 << endl;

	char c2 = (myScreen.*pmf2)(0,0);
	cout << c2 << endl;
	//====================================================================
	
	myScreen.move(Screen::HOME); // invokes myScreen.home
	myScreen.move(Screen::DOWN); // invokes myScreen.down



	return 0;
}

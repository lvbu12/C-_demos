#include <iostream>
#include <string>

using namespace std;

class Screen;

class Dog
{
public:
	int goo(Screen& sc);
};

class Screen
{
public:
	friend class Window_Mgr;
	friend int calcArea(Screen &);	
	friend int Dog::goo(Screen&);
//	friend int Dog::koo(Screen&);
	
	typedef string::size_type index;
	Screen(int ht=0, int wd=0): contents(ht*wd, ' '), cursor(0),height(ht),width(wd){}
	int area() const
	{ return height * width; }

private:
	string contents;
	index cursor;
	int height, width;
};

class Window_Mgr
{
public:
	void relocate(int r, int c, Screen& s)
	{
		s.height += r;
		s.width += c;
	}
};

/*
class Dog
{
public:
	int foo(Screen& sc)
	{
		return sc.height * sc.width;
	}
	int koo(Screen& sc)
	{
		return sc.height * sc.width;
	}
};
*/

int Dog::goo(Screen& sc)
{
	return sc.height * sc.width;
}

int calcArea(Screen & screen)
{
	return screen.height * screen.width;
}

int main()
{
	Screen sc(30,50);
	cout << sc.area() << endl;
	cout << calcArea(sc) << endl;
	Window_Mgr wm;
	wm.relocate(20, 100, sc);
	cout << calcArea(sc) << endl;
	return 0;
}

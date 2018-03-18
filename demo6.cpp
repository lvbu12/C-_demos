#include <iostream>

using namespace std;

class Person
{
public:
//	Person(const string &name, const string &addr): name(name),address(addr){}		// 不出错
//	Person(const string &name, const string &addr)
//	{
//		name = name;		// 出错
//		address = addr;
//	}
	Person(const string &name, const string &address)	
	{
		this->name = name;			// 不出错
		this->address = address;
	}
	string getName() const
	{ return name; }
	string getAddress() const
	{ return address; }

private:
	string name;
	string address;
};

class Screen
{
public:
	typedef string::size_type index;
	Screen(const index ht=0, const index wd=0): contents(ht*wd, 'A'),cursor(0),height(ht),width(wd){}
	char get() const { return contents[cursor]; }
	char get(const index r, const index c) const
	{
		index row = r * width;
		return contents[row + c];
	}
	Screen& move(const index r, const index c);
	Screen& set(const index r, const index c, const char ch);
	Screen& set(const char ch);
	const Screen& display(ostream &os) const
	{
		++ access_ctr;
		do_display(os);
		return *this;
	}
	Screen& display(ostream &os)
	{
		++ access_ctr;
		do_display(os);
		return *this;
	}
private:
	string contents;
	index cursor;
	index height, width;
	mutable size_t access_ctr;		// 计数

	void do_display(ostream &os) const
	{ os<<contents; }
};

Screen& Screen::move(const index r, const index c)
{
	index row = r * width;
	cursor = row + c;
	return *this;			// 必须用this指针
}

Screen& Screen::set(const index r, const index c, const char ch)
{
	index row = r * width;
	contents[row + c] = ch;
	return *this;
}

Screen& Screen::set(const char ch)
{
	contents[cursor] = ch;
	return *this;
}

int main()
{
	Person p("hello", "world");
	cout<<p.getName()<<", "<<p.getAddress()<<endl;

	Screen myScreen(5,3);
	cout<<myScreen.get()<<endl;
	
	myScreen.set(3, 2, 'B');
	cout<<myScreen.get(3, 2)<<endl;
	// 把下面两行合成一行：myScreen.move(2, 3).set('C')
//	myScreen.move(2, 3);
//	myScreen.set('C');
	myScreen.move(2, 3).set('C').display(cout).set('K').display(cout);
	cout<<endl;
	cout<<myScreen.get()<<endl;
	myScreen.display(cout);
	cout<<endl;
	return 0;
}

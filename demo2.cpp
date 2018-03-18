#include <iostream>
#include <string>

using namespace std;

class Screen
{
public:
	typedef string::size_type index;
	Screen(const index ht=0, const index wd=0):contents(ht*wd, 'A'), cursor(0), height(ht), width(wd)
	{}				// 第一种方法：将整个函数定义在类中。
	Screen(index ht, index wd, const string &conts);
	// 定义内联函数三种方法
	char get() const;		// 第二种方法：在类中声明函数，不带inline关键字，在类外部定义函数，带有inline关键字。
//	{
//		return contents[cursor];
//	}
	inline char get(const index r, const index c) const;			// 第三种方法：在类中用关键字inline声明函数，在类外部定义函数，不带inline关键字。
//	{
//		index row = r * width;
//		return contents[row + c];
//	}
	
private:
	string contents;
	index cursor;
	index height, width;
};

Screen::Screen(index ht, index wd, const string &conts):contents(conts),cursor(0),height(ht),width(wd)
{}

inline char Screen::get() const
{
	return contents[cursor];
}

char Screen::get(const index r, const index c) const
{
	index row = r * width;
	return contents[row + c];
}

int main()
{
	Screen a(30, 100);
	cout<<a.get()<<endl;
	cout<<a.get(2, 10)<<endl;
	Screen::index ids;
	return 0;
}

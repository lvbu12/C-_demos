#include <iostream>

using namespace std;

int height;

class ScreenB
{
public:
	typedef string::size_type index;
	void dummy_fcn(const index height)
	{
		//cursor = width * height;		// 这是哪一个height? 函数域中的height.
		//cursor = width * this->height;		// 类作用域里的height.
		cursor = width * ::height;			// 全局作用域中的height.
	}
private:
	index cursor;
	index height, width;
};

class ScreenA
{
public:
	typedef string::size_type index;
	char get(const index r, const index c) const;
	index get_cursor() const;
private:
	string contents;
	index cursor;
	index height, width;
};

ScreenA::index ScreenA::get_cursor() const
{
	return cursor;
}

char ScreenA::get(const index r, const index c) const
{
	index row = r * width;
	return contents[row + c];
}

int main()
{
	ScreenA s;
	return 0;
}

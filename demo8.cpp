#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(const string &nm): name(nm){}
private:
	string name;
	int age;
};

class Sales_item
{
public:
	Sales_item(const string &book, int units, double price)
		: isbn(book),units_sold(units),revenue(units * price)
	{}
	explicit Sales_item(const string &book=""): isbn(book),units_sold(0),revenue(0.0){}
	explicit Sales_item(istream &is) { is >> *this; }
	Sales_item(int units, double price)
	{
		this->units_sold = units;
		this->revenue = units * price;
	}
	//Sales_item():units_sold(0),revenue(0.0){}
	friend istream& operator >> (istream&, Sales_item&);
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

inline istream& operator >> (istream& in, Sales_item& s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;
	if(in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item();
	return in;
}

class Dog
{
public:
// 1. 引用类型的成员必须用初始化列表进行初始化。
// 2. 没有默认构造函数的类类型。
// 3. 类中的const 成员变量必须用初始化列表进行初始化, 自带的类型可以不在列表中。
	Dog():legs(4)
	{}
private:
// 初始化列表初始化成员变量的顺序 由下面定义成员变量的顺序决定。
	string name;
	const int legs;
};

class Data 		// Data v = {9, "hello"}	条件：1. 没有构造函数. 2. 数据成员全部为public.
{
public:
	int ival;
	char *ptr;
};

class Eata
{
public:
	Eata(int i, char *p): ival(i), ptr(p){}
private:
	int ival;
	char *ptr;
};

int main()
{
	Person p("zhangfei");
	Sales_item item1;
	Sales_item item2("0-201-82470-1");
	Sales_item *ps = new Sales_item();
	
	delete ps;
	return 0;
}

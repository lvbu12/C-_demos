#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_item
{
public:
	// 普通构造函数
	Sales_item(): units_sold(0),revenue(0.0)
	{ cout << "默认构造函数" << endl; }
	Sales_item(const string &book): isbn(book),units_sold(0),revenue(0.0)
	{ cout << "string 初始化构造函数" << endl; }

	string getIsbn() { return this->isbn; }

	// 复制构造函数
	Sales_item(const Sales_item &orig)
		: isbn(orig.isbn),units_sold(orig.units_sold),revenue(orig.revenue)
	{ cout << "复制构造函数被调用了！" << endl; }
	
	// 赋值操作符
	Sales_item& operator = (const Sales_item &rhs)
	{
		cout << "赋值操作符被调用了！" << endl;
		isbn = rhs.isbn;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		return *this;
	}	

private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

Sales_item foo(Sales_item item)
{
	Sales_item temp;
	temp = item;
	return temp;
}

class NoName
{
public:
	NoName() :pstr(new string),i(0),d(0) {}
	NoName(const NoName& other)
		:pstr(new string(*(other.pstr))),i(other.i),d(other.d)
	{ cout << "NoName Copy Constructor." << endl; }
	NoName& operator = (const NoName &rhs)
	{
		cout << "NoName 赋值操作符." << endl;
		pstr = new string;
		*pstr = *(rhs.pstr);
		i = rhs.i;
		d = rhs.d;
		return *this;
	}
private:
	string *pstr;
	int i;
	double d;
};

int main()
{
	NoName x, y;
	NoName z(x);
	x = y;
	Sales_item a;
	Sales_item b("0-201-78345-X");
	cout << b.getIsbn() << endl;
	Sales_item c(b);
	cout << c.getIsbn() << endl;
//	Sales_item d = c;
//	cout << d.getIsbn() << endl;	
	a = b;
	cout << a.getIsbn() << endl;
	Sales_item d = string("0-123-45678-X");
	cout << d.getIsbn() << endl;

	cout << endl << "试一下foo: " << endl;
	Sales_item ret;
	ret = foo(d);

	cout << endl << "试一下vector: " << endl;
	vector<Sales_item> svec(5);	

	cout << endl << "试一下数组: " << endl;
	Sales_item primer_eds[] = {
		string("0-201-16478-6"),
		string("0-201-54848-8"),
		string("0-201-82470-1"),
		Sales_item()
	};

	return 0;
}

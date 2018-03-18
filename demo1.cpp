#include <iostream>
#include <string>
using namespace std;

class Sales_item
{
public:
	Sales_item(const string &book, unsigned units, double amount)
		: isbn(book), units_sold(units), revenue(amount)
	{}
	double avg_price() const
	{
		if(units_sold)
			return revenue / units_sold;
		else
			return 0;
	}
	bool same_isbn(const Sales_item &rhs) const		// 因为成员函数并不修改成员变量isbn,units_sold和revenue, 所以定义函数后加上const
	{
		return isbn == rhs.isbn;
	}
	void add(const Sales_item &rhs)
	{
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
	}
private:
	string isbn;		// 书号
	unsigned units_sold;	// 销售数量
	double revenue;		// 总金额
};

/*
class Person
{
	// 成员
public:
	Person(const string &nm, const string &addr):name(nm),address(addr)
	{
		//name = nm;
		//address = addr;
	}
	string getName() const
	{
		return name;
	}
	string getAddress() const
	{
		return address;
	}
private:
	std::string name;
	std::string address;
};
*/

int main()
{
//	Person a("bob", "anhuisheng");
//	a.getName();
//	a.getAddress();
	Sales_item x("0-1234-666", 2, 50.00);
	Sales_item y("0-1234-666", 3, 60.00);
	cout<<"x average price: "<<x.avg_price()<<endl;	

	if(x.same_isbn(y))
	{
		x.add(y);
		cout<<"x average price: "<<x.avg_price()<<endl;
	}	

	cout<<"Hello 类！"<<endl;
	return 0;
}

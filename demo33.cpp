#include <iostream>
#include <string>

using namespace std;

class Item_base
{
public:
	Item_base(const string &book = "", double sales_price = 0.0):isbn(book), price(sales_price) {}
	string book() const { return isbn; }
	virtual double net_price(size_t n) const { return n * price; }
private:
	string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base
{
public:
	Bulk_item(const string &book="", double sales_price=0.0, size_t qty=0, double disc_rate=0.0)
		:Item_base(book, sales_price), min_qty(qty),discount(disc_rate) {}
	void test() { cout << price << endl; }
	double net_price(size_t cnt) const
	{
		if(cnt >= min_qty)
			return cnt * discount * price;
		else
  			return cnt * price;
	}
private:
	size_t min_qty;
	double discount;
};

void print_total_1(ostream &os, const Item_base item, size_t n)
{ os << "ISBN: " << item.book() << "\tnumber sold: " << n << "\t\ttotal price: " << item.net_price(n) << endl; }

void print_total_2(ostream &os, const Item_base *item, size_t n)
{ os << "ISBN: " << item->book() << "\tnumber sold: " << n << "\t\ttotal price: " << item->net_price(n) << endl; }
void print_total_3(ostream &os, const Item_base &item, size_t n)
{ os << "ISBN: " << item.book() << "\tnumber sold: " << n << "\t\ttotal price: " << item.net_price(n) << endl; }


int main()
{
	Item_base item("0-12-3456-789", 9.9);
	Bulk_item item2("0-12-3456-789", 9.9, 10, 0.8);

	print_total_1(cout, item, 10);
	print_total_1(cout, item2, 10);			// 对象转换, 有问题
	cout << endl;	

	print_total_2(cout, &item, 10);
	print_total_2(cout, &item2, 10);		// 指针转换, 打折，没问题
	cout << endl;

	print_total_3(cout, item, 10);
	print_total_3(cout, item2, 10);			// 引用转换, 打折，没问题
	cout << endl;

//	item2 = item;	出错，把基类对象 赋值给 派生类对象
	item = item2;		// 把派生类对象 赋值给 基类对象

	Bulk_item *p = static_cast<Bulk_item *> (&item);		// 利用指针，强制转换，把基类地址赋值给子类指针
	cout << p->net_price(10) << endl;

	return 0;
}

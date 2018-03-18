#include <iostream>
#include <string>

using namespace std;

class Item_base
{
public:
	Item_base(const string &book="", const double _price=0.0):isbn(book),price(_price) {}
	string book() const
	{ return isbn; }
	virtual double net_price(size_t n) const
	{ return n * price; }
private:
	string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base
{
public:
	Bulk_item(const string &book="", double _price=0.0, size_t _qty=10, double disc_rate=0.8)
		: Item_base(book, _price), min_qty(_qty), discount(disc_rate) {}
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

// 能够接收基类对象的地方，都可以传递一个子类对象
void print_total(ostream &os, Item_base *item, size_t n)
{
	os << "ISBN: " << item->book() << "\tnumber sold: " << n << "\ttotal price: " << item->net_price(n) << endl;
}

/*
动态绑定：
~ 多态性
~ 从派生类到基类的转换
~ 引用或指针既可以指向基类对象，也可以指向派生类对象
~ 只有通过引用或指针调用虚函数才会发生动态绑定
*/

int main()
{
	Item_base* a = new Item_base("1-234-567-01", 10.0);
	Bulk_item* b = new Bulk_item("1-234-567-02", 10.0, 5, 0.8);
	print_total(cout, a, 10);
	print_total(cout, b, 10);
	cout << endl;
//	Item_base ib("X-0123-456-7", 9.9);
//	cout << ib.net_price(20) << endl;
//	Bulk_item bi("X-0123-456-7", 9.9, 10, 0.8);
//	cout << bi.net_price(20) << endl;
	Item_base* books[5];
	books[0] = new Item_base("0-123-456-01", 10.0);
	books[1] = new Bulk_item("0-123-456-02", 10.0, 5, 0.8);
	books[2] = new Item_base("0-123-456-03", 30.0);
	books[3] = new Bulk_item("0-123-456-04", 40.0, 4, 0.9);
	books[4] = new Bulk_item("0-123-456-05", 50.0, 5, 0.8);
	int num[5];
	num[0] = 2;
	num[1] = 10;
	num[2] = 1;
	num[3] = 5;
	num[4] = 3;
	for(int i=0; i<5; ++i)
		print_total(cout, books[i], num[i]);

	return 0;
}

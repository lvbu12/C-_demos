#include <iostream>
#include <string>

using namespace std;

class Animal
{
	
};

class Dog: public Animal
{

};

class Cat: public Animal
{

};

class Item_base
{
public:
	int x;
	Item_base(int _x, const string _isbn, double _price): x(_x),isbn(_isbn),price(_price) {}
	string book() const
	{ return isbn; }
	virtual double net_price() const
	{ return x * price; }
private:
	string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base
{
public:
	Bulk_item(const int _x,const string _isbn, const double _price, const size_t _min_qty, const double _discount)
		:Item_base(_x, _isbn, _price),min_qty(_min_qty),discount(_discount)	{}
	void test()
	{
		cout << x << endl;
		cout << price << endl;
	}
	void test2(const Bulk_item& bi, const Item_base& ib)
	{
		cout << bi.x << endl;
		cout << bi.price << endl;
		cout << ib.x << endl;
//		cout << ib.price << endl;
	}
	double net_price() const
	{
		if(x >= min_qty)
			return x * discount * price;
		else
			return x * price;
	}
private:
	size_t min_qty;
	double discount;
};

int main()
{
	Animal a;
	Dog d;
	Cat c;

	Item_base item(10,"X-0123-456-7",9.9);
	cout << item.book() << "\t" << item.net_price() << endl;

	Bulk_item item2(10, "X-0123-456-7", 9.9, 10, 0.8);
//	item2.test2(item2, item);
	cout << item2.book() << '\t' << item2.net_price() << endl;
	
	return 0;
}

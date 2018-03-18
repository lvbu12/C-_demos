#include <iostream>
#include <string>

using namespace std;

class Sales_item
{
	friend istream& operator >> (istream& in, Sales_item& s);
	friend ostream& operator << (ostream& out, const Sales_item& s);
public:
	Sales_item(): units_sold(0),revenue(0.0) {}
	Sales_item(const string &book, unsigned units, double price):
		isbn(book),units_sold(units),revenue(price * units) {}
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};


ostream& operator << (ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue;
	return out;
}

istream& operator >> (istream& in, Sales_item& s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;
	if(in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item();
	return in;
}

int main()
{
	Sales_item a("0-1234-567-X", 2, 20.00);
	cout << a << endl;
	
	cin >> a ;
	cout << a << endl;
	return 0;
}

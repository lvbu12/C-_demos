#include <iostream>
#include <string>

using namespace std;

class Sales_item
{	
	friend bool operator == (const Sales_item&, const Sales_item&);
	friend ostream& operator << (ostream& out, const Sales_item& s);
public:
	Sales_item(const string& book, const unsigned units, const double amount)
		:isbn(book),units_sold(units),revenue(amount) {}
	Sales_item& operator += (const Sales_item&);
	Sales_item& operator -= (const Sales_item&);
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

inline bool operator == (const Sales_item& lhs, const Sales_item& rhs)
{
	return lhs.isbn==rhs.isbn && lhs.units_sold==rhs.units_sold && lhs.revenue==rhs.revenue;
}

bool operator != (const Sales_item& lhs, const Sales_item& rhs)
{
	return !(lhs == rhs);
}

ostream& operator << (ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue;
	return out;
}

Sales_item& Sales_item::operator -= (const Sales_item& rhs)
{
	this->units_sold -= rhs.units_sold;
	this->revenue -= rhs.revenue;
	return *this;
}

Sales_item& Sales_item::operator += (const Sales_item& rhs)
{
	this->units_sold += rhs.units_sold;
	this->revenue += rhs.revenue;
	return *this;
}

Sales_item operator + (const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

Sales_item operator - (const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;
	return ret;
}

int main()
{
	Sales_item s1("0-1234-5678-X", 2, 40);
	Sales_item s2("0-1234-5678-X", 2, 40);
	cout << (s1 == s2) << endl;
	cout << (s1!=s2) << endl;
//	Sales_item s = s1 + s2;
//	cout << s << endl;
//	s -= s1;
//	cout << s << endl;
	return 0;
}

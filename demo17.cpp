#include <iostream>

using namespace std;

class Date
{
public:
	Date(int m=0, int d=0, int y=0):month(m),day(d),year(y) {}
	int operator == (Date& dt) const;
	int operator != (Date& dt) const;

	int operator < (Date& dt) const;
	int operator > (Date& dt) const;
	int operator <= (Date& dt) const;
	int operator >= (Date& dt) const;

private:
	int month, day, year;
};

int Date::operator == (Date& dt) const
{
	return (this->month == dt.month) && (this->day == dt.day) && (this->year == dt.year);
}

int Date::operator != (Date& dt) const
{
	return !(*this == dt);
}

int Date::operator < (Date& dt) const
{
	if(this->year == dt.year)
	{
		if(this->month == dt.month)
		{
			if(this->day == dt.day)
				return 0;
			else
				return this->day < dt.day;
		}
		else
			return this->month < dt.month;
	}
	else
		return this->year < dt.year;
}

int main()
{
	Date d1(2, 14, 2008);
	Date d2(3, 14, 2008);
	Date d3(2, 14, 2008);

	cout << "d1 == d2 : " << (d1 == d2) << endl;
	cout << "d1 == d3 : " << (d1 == d3) << endl;
	cout << "d1 != d2 : " << (d1 != d2) << endl;
	return 0;
}

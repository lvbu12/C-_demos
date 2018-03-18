#include <iostream>
#include <string>

using namespace std;

class Dog
{
public:
	Dog(string str, int a, double w):name(str),age(a),weight(w) {}
	operator int() const
	{ return age; }
private:
	int age;
	double weight;
	string name;
};

int main()
{
	int a, b;
	a = 10;
	b = a;
	cout << "b: " << b << endl;
	Dog d("Bill", 6, 15.0);
	b = d;
	cout << "b: " << b << endl;
	return 0;
}

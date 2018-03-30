#include <iostream>

using namespace std;

/*
友元关系不能继承，要明确授予友元。
*/

class Base
{
	friend class Frnd;
	friend class D2;
protected:
	int i;
};

class D1 : public Base
{
	friend class Frnd;
	friend class D2;
private:
	int j;
};

class Frnd
{
public:
	int mem(Base b) { return b.i; }
	int mem(D1 d) { return d.j; }
};

class D2 : public Frnd
{
public:
	int mem(Base b) { return b.i; }
	int mem(D1 d) { return d.j; }
};

int main()
{
	Base b;
	D1 d1;
	Frnd f;
	D2 d2;

	return 0;
}

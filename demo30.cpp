#include <iostream>

using namespace std;

class A
{
public:
	A():a(1),b(2),c(3),d(10),e(20) {}
	int a;
	int d;
	int e;
protected:
	int b;
private:
	int c;
};

class B1 : public A
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
//		cout << c << endl;
	}
};

class C1 : public B1
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

class B2 : private A
{
public:
	using A::d;		// 将d变成公有的.
	void test()
	{
		cout << a << endl;
		cout << b << endl;
//		cout << c << endl;
	}
};

class B3 : protected A
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
//		cout << c << endl;
	}
};

class B4 : A		// 默认是private继承
{
	int x;			// 默认的是private
};

struct B5 : A		// 默认是public继承
{
	int y;			// 默认是公有的public
};

int main()
{
	B1 b1;
	cout << b1.a << endl;
	b1.test();
//	cout << b1.b << endl;
//	cout << b1.c << endl;
	B2 b2;
	b2.test();
	cout << b2.d << endl;
//	cout << b2.e << endl;
//	cout << b2.a << endl;
//	cout << b2.b << endl;
	B3 b3;
	b3.test();
//	cout << b3.a << endl;
//	cout << b3.b << endl;
//	cout << b3.c << endl;

	return 0;
}

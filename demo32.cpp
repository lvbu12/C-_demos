#include <iostream>

using namespace std;

class Base
{
public:
	Base():b1(0),b2(0)
	{ cout << "Base 调用构造函数！" << b1 << ", " << b2 << endl; }
	Base(int i, int j):b1(i), b2(j)
	{ cout << "Base 调用构造函数！" << b1 << ", " << b2 << endl; }
	~Base()
	{ cout << "Base 调用析构函数！" << b1 << ", " << b2 << ", " << endl; }
	void Print()
	{ cout << b1 << ", " << b2 << ", "; }
private:
	int b1, b2;
};

/*
派生类的析构规则：
1、对派生类新增普通成员进行清理
2、调用成员对象析构函数
3、调用基类析构函数
*/

class Derived : public Base
{
public:
	Derived(int i, int j, int k);
	~Derived();
	void Print();
private:
	int d;
};

Derived::Derived(int i, int j, int k): Base(i, j), d(k)
{
	cout << "Derived 调用构造函数！" << d << endl;
}
Derived::~Derived()
{
	cout << "Derived 调用析构函数！" << d << endl;
}

void Derived::Print()
{
	Base::Print();
	cout << d << endl;
}

int main()
{
	Derived der1(1,2,3), der2(-4,-5,-6);
	der1.Print();
	der2.Print();

	return 0;
}

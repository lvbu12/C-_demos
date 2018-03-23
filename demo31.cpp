#include <iostream>

using namespace std;

class Base1
{
public:
	Base1(int i): b1(i)
	{ cout << "Base1 构造函数被调用！" << endl; }
	void print() const
	{ cout << "b1 -> " << b1 << endl; }
	
private:
	int b1;
};

class Base2
{
public:
	Base2(int i): b2(i)
	{ cout << "Base2 构造函数被调用！" << endl; }
	void print() const
	{ cout << "b2 -> " << b2 << endl; }
private:
	int b2;
};

class Base3
{
public:
	Base3(): b3(0)
	{ cout << "Base3 构造函数被调用！" << endl; }
	void print() const
	{ cout << "b3 -> " << b3 << endl; }
private:
	int b3;
};

class Member
{
public:
	Member(int i): m(i)
	{ cout << "Member 的构造函数被调用！" << endl; }
	int GetM()
	{ return m; }
private:
	int m;
};

/*
派生类构造规则：
1、先执行基类的构造函数
2、再执行成员对象的构造函数
3、最后执行派生类自己的构造函数

*/
// 执行基类的构造函数时，按照定义时基类的列出顺序进行构造
class Derived : public Base1, public Base2, public Base3
{
public:
	Derived(int i, int j, int k, int l);
	void print();
private:
	int d;
	Member mem;
};

Derived::Derived(int i, int j, int k, int l): Base1(i), Base2(j), mem(k)
{
	d = l;
	cout << "Derived 的构造函数被调用." << endl;
}

void Derived::print()
{
	cout << "d -> " << d << endl;
	cout << "memeber 's m -> " << mem.GetM() << endl;
}

int main()
{
	Derived der(1,2,3,4);
	der.print();

	return 0;
}

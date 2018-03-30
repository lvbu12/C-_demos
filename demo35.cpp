#include <iostream>

using namespace std;

/*
1、基类中的 static 成员，在整个继承层次中只有一个实例。
2、在派生类中访问 static 成员的方法：
	a. 基类名::成员名
	b. 子类名::成员名
	c. 对象.成员名
	d. 指针->成员名
	5. 成员名
*/

class A
{
public:
	static size_t object_count()
	{ return 100; }
protected:
	static const size_t obj_count = 99;
};

class B : A
{
public:
	void f(const B& b, const B* b2)
	{
		cout << A::obj_count << endl;
		cout << B::obj_count << endl;
		cout << b.obj_count << endl;
		cout << b2->obj_count << endl;
		cout << obj_count << endl;
		cout << A::object_count() << endl;
		cout << B::object_count() << endl;
		cout << b.object_count() << endl;
		cout << b2->object_count() << endl;
		cout << object_count() << endl;
	}
};

class C : A
{
public:
	void f_c(const C& c, const C* c2)
	{
		cout << A::obj_count << endl;
		cout << C::obj_count << endl;
		cout << c.obj_count << endl;
		cout << c2->obj_count << endl;
		cout << obj_count << endl;
		
		cout << A::object_count() << endl;
		cout << C::object_count() << endl;
		cout << c.object_count() << endl;
		cout << c2->object_count() << endl;
		cout << object_count() << endl;
	}
};

int main()
{
	B b;
	b.f(b, &b);

	C c;
	c.f_c(c, &c);

	return 0;
}

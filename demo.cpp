#include <iostream>
#include "plain_ptr.h"
#include "value_ptr.h"
#include "smart_ptr.h"

using namespace std;

void test_1()
{
	int i = 42;
	AHasPtr p1(&i, 20);
	AHasPtr p2 = p1;
	cout << p2.get_ptr_val() << endl;

	p1.set_ptr_val(0);
	cout << p2.get_ptr_val() << endl;
}

void test_2()
{
	int obj = 0;
	CHasPtr ptr1(obj, 42);
	CHasPtr ptr2(ptr1);
	
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;

	ptr2.set_ptr_val(6);
	ptr2.set_int(48);
	cout << "修改以后: " << endl;
	
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
}

void test_3()
{
	int obj = 0;
	BHasPtr ptr1(&obj, 42);
	BHasPtr ptr2(ptr1);
	
	cout << ptr1.get_ptr_val() << ", " << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << ", " << ptr2.get_int() << endl;
}

int main()
{
//	test_1();
//	cout << "值型类: " << endl;
//	test_2();
	cout << "智能指针: " << endl;
	test_3();
	return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

class CDemo
{
public:
	CDemo(const int pa, const char *cstr)
	{
		this->a = pa;
		this->str = new char[1024];
		strcpy(this->str, cstr);
	}
// 我没写的话，C++会自动帮我写一个复制构造函数.
	CDemo(CDemo& obj)
	{
		this->a = obj.a;
		// this->str = obj.str;		// 这里不对，要深复制才行，这是浅复制。
		this->str = new char[1024];
		if(str != 0)
			strcpy(this->str, obj.str);
	}
	~CDemo()
	{ delete str; }
public:
	int a;
	char *str;
};

int main()
{
	CDemo A(10, "hello");
	cout << "A: " << A.a << ", " << A.str << endl;
	CDemo B = A;
	cout << "B: " << B.a << ", " << B.str << endl;

	cout << "修改一下: " << endl;
	B.a = 8;
	B.str[0] = 'k';
	cout << "A: " << A.a << ", " << A.str << endl;
	cout << "B: " << B.a << ", " << B.str << endl;

	return 0;
}

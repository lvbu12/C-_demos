#include <iostream>
#include <string>

using namespace std;

class NoName
{
public:
	NoName() :pstr(new string),i(0),d(0) {}
	~NoName();
private:
	string *pstr;
	int i;
	double d;
};

NoName::~NoName()
{
	cout << "析构函数被调用了!\n" << endl;
	delete pstr;
}

int main()
{
	cout << "Hello\n" << endl;
	return 0;
}

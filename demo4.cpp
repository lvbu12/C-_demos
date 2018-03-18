#include <iostream>
#include <string>

using namespace std;

class Screen;		// 类声明

class LinkScreen	// 到这里，LinkScreen类已声明
{
	Screen *window;
	LinkScreen *next;	// 可定义类LinkScreen的指针，但不可定义LinkScreen对象。
	LinkScreen *prev;
};

class Y;

class X
{

private:
	Y *ptr;
};

class Y
{
private: 
	X *ptr;
	X obj;
};

//	记录
class Record
{
public:
	typedef size_t size;
	Record(): byte_count(0){}
	Record(size s): byte_count(s){}
	Record(string s): name(s), byte_count(0){}
	
	size get_count() const { return byte_count; }
	string get_name() const { return name; }

private:
	size byte_count;
	string name;		// 记录名称	
};

struct Person
{
public:
	Person(const string &nm, const string &addr): name(nm), address(addr){}
	string getName() const { return name; }
	string getAddress() const { return address; }	

private:
	string name;
	string address;
};

int main()
{
	X x;
	Record r;		// 在堆栈上创建类的对象。
	class Record r2;	// 传统C语言写法
	
	Person pp("ha", "ha");
		
	Record *p = new Record;		// 在堆上动态地创建对象。
	
	delete p;
	return 0;
}

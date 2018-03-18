#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
	String(char const *chars = "");
	String(String const &str);
	~String();

	void display() const;

	String& operator ++();			// 前加加
	String const operator ++(int);		// 后加加
	String& operator --();			// 前减减
	String const operator --(int);		// 后减减

private:
	char *ptrChars;
};

String& String::operator ++()
{
	for(size_t i=0; i<strlen(ptrChars); ++i)
		++ptrChars[i];
	return *this;
}

String const String::operator ++(int)
{
	String tmp(*this);
	++(*this);
	return tmp;
}

String::String(char const *chars)
{
	chars = chars ? chars : "";
	ptrChars = new char[strlen(chars) + 1];
	strcpy(ptrChars, chars);
}

String::String(String const &str)
{
	ptrChars = new char[strlen(str.ptrChars) + 1];
	strcpy(ptrChars, str.ptrChars);
}

String::~String()
{
	delete[] ptrChars;
}

void String::display() const
{
	cout << ptrChars << endl;
}

int main()
{
	String s("Hello, World!");
	s.display();
	
	String s1("ABC");
	cout << "s1 : " <<endl;
	s1.display();
	String s2(++s1);
	cout << "s2 : " << endl;
	s2.display();
	String s3("ABC");
	cout << "s3 : " << endl;
	s3.display();
	String s4(s3++);
	cout << "s4 : " << endl;
	s4.display();

	return 0;
}

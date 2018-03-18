#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
//	String(char const *chars = "");
	String(const char *chars = "");

	void print();
//	String& operator = (const String &);
	String& operator = (String const &);
	String& operator = (char const *);
	String& operator = (char);
private:
	char *ptrChars;
};

//String::String(char const *chars)
String::String(const char *chars)
{
	chars = chars ? chars : "";
	ptrChars = new  char[strlen(chars) + 1];
	strcpy(ptrChars, chars);
}

//String& String::operator = (const String &tg)
String& String::operator = (String const &tg)
{
	if(strlen(ptrChars) != strlen(tg.ptrChars))
	{
		char *tmp = new char[strlen(tg.ptrChars) + 1];
		delete[] ptrChars;
		ptrChars = tmp;
	}
	strcpy(ptrChars, tg.ptrChars);
	return *this;
}

void String::print()
{
	cout << ptrChars << endl;
}

int main()
{
	String s("hello");
	s.print();	
	String s2("Dog");
	s = s2;
	s.print();	
	return 0;
}

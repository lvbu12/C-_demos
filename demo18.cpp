#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
//	String(const char* chars);
	String(char const *chars = "");

	String& operator = (String const &);
	void print();
private:
	char* ptrChars;
};

String::String(char const *chars)
{
	chars = chars ? chars : "";
	ptrChars = new char[strlen(chars) + 1];
	strcpy(ptrChars, chars);
}

void String::print()
{
	cout << ptrChars << endl;
}

String& String::operator = (String const &str)
{
	if(strlen(this->ptrChars) != strlen(str.ptrChars))
	{
		char* ptrHold = new char[strlen(str.ptrChars) + 1];
		delete[] ptrChars;
		ptrChars = ptrHold;
	}
	strcpy(ptrChars, str.ptrChars);
	return *this;
}

int main()
{
	String a("hello");
	String b("Dog");

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;

	a = b;

	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	return 0;
}

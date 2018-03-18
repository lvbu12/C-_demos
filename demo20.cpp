#include <iostream>
#include <cstring>
#include <string>

using namespace std;


class String
{
public:
	String(char const *chars = "");

	char& operator [](size_t index) throw(string);
	char operator [](size_t index) const throw(string);

	void print()
	{ cout << ptrChars << endl; }
private:
	char *ptrChars;
	static string errorMessage;
};

string String::errorMessage("Subscript out of range");

String::String(char const *chars)
{
	chars = chars ? chars : "";
	ptrChars = new char[strlen(chars) + 1];
	strcpy(ptrChars, chars);
}

char& String::operator [](size_t index) throw(string)
{
	if(index >= strlen(ptrChars))
		throw errorMessage;
	return ptrChars[index];
}

char String::operator[](size_t index) const throw(string)
{
	if(index >= strlen(ptrChars))
		throw errorMessage;
	return ptrChars[index];
}

int main()
{
	String s("Hello");	
	s.print();
	cout << s[0] << endl;
	return 0;
}

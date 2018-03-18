#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

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


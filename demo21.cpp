#include <iostream>
#include "String.h"
#include "pointer.h"

using namespace std;

int main()
{
	String s("hello");
	s.display();

	String *ps = &s;
	ps->display();

	try
	{
		Pointer p1("C++");
		p1->display();
		
		String s = *p1;
		Pointer p2;
		p2->display();
	}
	catch(String const &error)
	{
		error.display();
	}

	return 0;
}

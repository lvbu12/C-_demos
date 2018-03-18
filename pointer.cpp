#include "pointer.h"
#include "String.h"

Pointer::Pointer() : ptr(0) {}

Pointer::Pointer(String const &n)
{
	ptr = new String(n);
}

Pointer::~Pointer()
{
	delete ptr;
}

String Pointer::errorMessage("Uninitialized pointer!");

String& Pointer::operator *()
{
	if(!ptr)
		throw errorMessage;
	return *ptr;
}

String* Pointer::operator ->() const
{
	if(!ptr)
		throw errorMessage;
	return ptr;
}

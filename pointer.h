#ifndef POINTER_H
#define POINTER_H

class String;

class Pointer
{
public:
	Pointer();
	Pointer(String const &n);
	~Pointer();
	
	String& operator *();
	String* operator ->() const;

private:
	String *ptr;
	static String errorMessage;
};

#endif


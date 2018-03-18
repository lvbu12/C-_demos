#ifndef STRING_H
#define STRING_H

class String
{
public:
	String(char const *chars = "");
	String(String const &str);
	~String();

	void display() const;
private:
	char* ptrChars;
};

#endif

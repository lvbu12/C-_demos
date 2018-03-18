#include <stdio.h>
#include <string.h>

struct Person		// C语言中struct 成员默认都是公有的(public)，C++ class 成员默认都是私有的(private).
{
	char name[30];
	char address[100];
};

int main()
{
	struct Person p;
	strcpy(p.name, "Bill");
	strcpy(p.address, "花园街5号");

	printf("%s, %s\n", p.name, p.address);
	printf("hello C!\n");
	return 0;
}


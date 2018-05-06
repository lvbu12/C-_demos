#include "stdio.h"

class BadSrcFile {};
class BadDestFile {};
class BadCopy {};

int my_cp(const char* src_file, const char* dest_file)
{
	FILE *in_file, *out_file;
	in_file = fopen(src_file, "rb");
	if(in_file == NULL)
		return 1;
	out_file = fopen(dest_file, "wb");
	if(out_file == NULL)
		return 2;
	char rec[256];
	size_t bytes_in, bytes_out;
	while((bytes_in = fread(rec, 1, 256, in_file)) > 0)
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);
		if(bytes_in != bytes_out)
			return 3;
	}

	return 0;
}

void my_cp_02(const char* src_file, const char* dest_file)
{
	FILE *in_file, *out_file;
	in_file = fopen(src_file, "rb");
	if(in_file == NULL)
		throw 1;
	out_file = fopen(dest_file, "wb");
	if(out_file == NULL)
		throw 2;
	char rec[256];
	size_t bytes_in, bytes_out;
	while((bytes_in = fread(rec, 1, 256, in_file)) > 0)
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);
		if(bytes_in != bytes_out)
			throw 3;
	}
}


void my_cp_03(const char* src_file, const char* dest_file)
{
	FILE *in_file, *out_file;
	in_file = fopen(src_file, "rb");
	if(in_file == NULL)
		throw "Error occurs when open the source file.";
	out_file = fopen(dest_file, "wb");
	if(out_file == NULL)
		throw "Error occurs when open the target file.";
	char rec[256];
	size_t bytes_in, bytes_out;
	while((bytes_in = fread(rec, 1, 256, in_file)) > 0)
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);
		if(bytes_in != bytes_out)
			throw "Error occurs when write the content from source file to target file.";
	}
}


void my_cp_04(const char* src_file, const char* dest_file)
{
	FILE *in_file, *out_file;
	in_file = fopen(src_file, "rb");
	if(in_file == NULL)
		throw BadSrcFile();
	out_file = fopen(dest_file, "wb");
	if(out_file == NULL)
		throw BadDestFile();
	char rec[256];
	size_t bytes_in, bytes_out;
	while((bytes_in = fread(rec, 1, 256, in_file)) > 0)
	{
		bytes_out = fwrite(rec, 1, bytes_in, out_file);
		if(bytes_in != bytes_out)
			throw BadCopy();
	}
}

int main()
  {
  	int result;
  	if((result = my_cp("1.txt", "2.txt")) != 0)
  	{
  		switch(result)
  		{
  			case 1:
  				printf("Error occurs when open the source file.\n");
  				break;
  			case 2:
  				printf("Error occurs when open the target file.\n");
  				break;
  			case 3:
  				printf("Error occurs when write the content to target file.\n");
  				break;
  			default:
 				printf("Unkonwn error occurs.\n");
				break;
		}
	}
	try
	{
		my_cp_02("1.txt", "3.txt");
		my_cp_03("1.txt", "4.txt");
		my_cp_04("11.txt", "5.txt");
	}
	catch(int e)
	{
//		printf("Exception occurs: %d\n", e);
  		switch(e)
  		{
  			case 1:
  				printf("Error occurs when open the source file.\n");
  				break;
  			case 2:
  				printf("Error occurs when open the target file.\n");
  				break;
  			case 3:
  				printf("Error occurs when write the content to target file.\n");
  				break;
  			default:
 				printf("Unkonwn error occurs.\n");
				break;
		}
	}
	catch(const char* e)
	{
		printf("throw a string: %s\n", e);
	}
	catch(BadSrcFile e)
	{ printf("throw object: Error occurs when open the source file.\n"); }
	catch(BadDestFile e)
	{ printf("throw object: Error occurs when open the target file.\n"); }
	catch(BadCopy e)
	{ printf("throw object: Error occurs when write content from source file to target file.\n"); }
	catch(...)
	{ printf("Unkonwn error occurs.\n"); }

	return 0;
}

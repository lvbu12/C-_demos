#include <iostream>

using namespace std;

class Dog
{
public:
	Dog()
	{ parr = new int[1024 * 1024]; }

private:
	int *parr;
};

int main()
{
	Dog *pDog;
	try
	{
		for(int i=1; i<1000000; ++i)
		{
			pDog = new Dog();
			cout << i << ": new Dog 成功." << endl;
		}
	}
	catch(bad_alloc err)
	{
		{
			cout << "new Dog 失败: " << err.what() << endl;
		}
	}

	return 0;
}

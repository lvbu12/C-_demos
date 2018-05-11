#include <iostream>

using namespace std;

const int DefaultSize = 10;

class Array
{
public:
	Array(int itsSize = DefaultSize);
	~Array() { delete [] pType; }

	int& operator [](int idx);
	const int& operator [] (int idx) const;

	int size() { return itsSize; }

	class xBoundary{};
private:
	int *pType;
	int itsSize;
};

Array::Array(int size):itsSize(size)
{
	pType = new int[size];
	for(int i=0; i<size; ++i)
		pType[i] = 0;
}

int& Array::operator [] (int idx)
{
	int size = this->size();
	if(idx >= 0 && idx < size)
		return pType[idx];
	else
		throw xBoundary();
}

const int& Array::operator [] (int idx) const
{
//	int size = this->size();
	int size = this->itsSize;
	if(idx >= 0 && idx < size)
		return pType[idx];
	else
		throw xBoundary();
}

int main()
{
	Array a;
	Array b(12);
	try
	{
		cout << b.size() << '\t' << b[0] << endl;
		b[20] = 6;
		cout << "b[6] -> " << b[6] << endl; 
		cout << "测试一下" << endl;
	}
	catch(Array::xBoundary)
	{
		cout << "index out of range!" << endl;
	}
	catch(...)
	{ cout << "Some Error unknown happens."; }
	return 0;
}

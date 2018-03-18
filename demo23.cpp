#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct absInt
{
	// 重载操作符: 函数调用操作符
	int operator()(int val){
		return val < 0 ? -val : val;
	}
};

template<typename elementType>
void FuncDisplayElement(const elementType & element)
{
	cout << element << " ";
}

template<typename elementType>
struct DisplayElement
{
	int cnt;
	DisplayElement()
	{ cnt = 0; }
	void operator()(const elementType & element) 
	{
		cout << element << ' ';
		++cnt;
	}
};

int main()
{
	int i = -42;
	absInt absObj;
	unsigned int ui = absObj(i);
	cout << ui << endl;
	vector<int> vec;
	for(int i=0; i<10; ++i)
		vec.push_back(i);
	list<char> lst;
	for(char c='a'; c<'k'; ++c)
		lst.push_back(c);
	
	DisplayElement<int> mResult;
	mResult = for_each(vec.begin(), vec.end(), mResult);
	cout << endl;
	cout << "数量：" << mResult.cnt << endl;

	mResult = for_each(lst.begin(), lst.end(), mResult);
	cout << endl;
	cout << mResult.cnt << endl;

	return 0;
}

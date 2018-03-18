#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename numberType>
struct IsMultiple
{
	int m_Divisor;
	IsMultiple(const numberType& divisor)
	{ m_Divisor = divisor; }
	bool operator() (const numberType& element) const
	{ return ((element % m_Divisor) == 0); }
};

int main()
{
	vector<int> vecInt;
	for(int i=1; i<=100; ++i)
		vecInt.push_back(i);
	IsMultiple<int> a(4);
	vector<int>::iterator eleIer;
	eleIer = find_if(vecInt.begin(), vecInt.end(), a);
	while(eleIer != vecInt.end())
	{ 
		cout << "第一个4的整数倍的数是：" << *eleIer << endl;
		eleIer = find_if(eleIer+1, vecInt.end(), a);
	 }

	return 0;
}

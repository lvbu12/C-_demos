#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename elemType>
class CMultiply
{
public:
	elemType operator() (const elemType& elem1, const elemType& elem2)
	{ return elem1 * elem2; }
	
};

int main()
{
	vector<int> a,b;
	for(int i=0; i<10; ++i)
		a.push_back(i);
	for(int j=100; j<110; ++j)
		b.push_back(j);
	vector<int> vecRes;
	vecRes.resize(10);
	transform(a.begin(), a.end(), b.begin(),vecRes.begin(), CMultiply<int>());	

	for(size_t i=0; i<vecRes.size(); ++i)
		cout << vecRes[i] << ' ';
	cout << endl;

	CMultiply<int> cmu;
	cout << cmu(3, 5) << endl;
	return 0;
}

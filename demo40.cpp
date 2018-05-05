#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>
int  compare(T& data1, T& data2)
{
	if(data1 > data2)
		return 1;
	else if(data1 < data2)
		return -1;
	else
		return 0;
}

template <typename T>
T absVal(T data)
{
//	T new_data = data>0 ? data : -data;
	return data > 0 ? data : -data;
}

template <typename T1, typename T2>
T1& print(T1& s, T2 val)
{
	s << val;
	return s;
}

template <class T>
const T& bigger(const T& v1, const T& v2)
{
	return v1 > v2 ? v1 : v2;
}

int main()
{
	double dval = -0.88;
	float fval = -12.3;
	cout << absVal(dval) << endl;
	cout << absVal(fval) << endl;

	string oristr = "this is a test";
	string desstr;
	ostringstream oss(desstr);
	ofstream outFile("result.dat");
	
//	print(cout, -3) << endl;
//	print(cout, dval) << endl;
//	print(cout, fval) << endl;
//	print(cout, oristr) << endl;
//
//	print(outFile, -3) << endl;
//	print(outFile, dval) << endl;
//	print(outFile, fval) << endl;
//	print(outFile, oristr) << endl;

	print(oss, -3) << endl;
	print(oss, dval) << endl;
	print(oss, oristr) << endl;
//	cout << desstr << endl;
	cout << oss.str() << endl;
//	string str1 = "hello";
//	cout << absVal(str1) << endl;

	double d1 = 1.23;
	double d2 = 9.56;
	cout << compare(d1, d2) << endl;
	
	string s1 = "hello";
	string s2 = "world";
	cout << compare(s1, s2) << endl;

	cout << bigger(d1, d2) << endl;
	cout << bigger(s1, s2) << endl;

	return 0;
}

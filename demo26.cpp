#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

class CCompareStringNoCase
{
public:
	bool operator() (const string& str1, const string& str2) const
	{
		string str1LowerCase;
		str1LowerCase.resize(str1.size());
		transform(str1.begin(), str1.end(), str1LowerCase.begin(), ::tolower);
		string str2LowerCase;
		str2LowerCase.resize(str2.size());
		transform(str2.begin(), str2.end(), str2LowerCase.begin(), ::tolower);
		
		return (str1LowerCase < str2LowerCase);
	}
};

int main()
{
	set<string, CCompareStringNoCase> names;
	names.insert("Tine");
	names.insert("jim");
	names.insert("Jack");
	names.insert("Sam");
	names.insert("hello");
	
	set<string, CCompareStringNoCase>::iterator iset = names.find("SAM");
	if(iset != names.end())
		cout << "Find it! " << *iset << endl;
	else
		cout << "Does not find it! " << endl;

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

// 全局变量
//double interestRate;

class Dog
{
private:
	static double interestRate;		// 类作用域的 interestRate
};

class Account
{
public:
	Account(const string name, double money):
		owner(name), amount(money)
	{}
	double getAmount() const
	{
		return this->amount;
	}
	
	void applyint() { amount += amount * interestRate; }	

	void deposit(double money)
	{ this->amount += money; }
	static double rate() { return interestRate; }
	static void rate(double newRate)
	{ interestRate = newRate; }
private:
	string owner;
	double amount;
//	double interestRate;
	static double interestRate;		// 只有一个
};

double Account::interestRate = 0.015;

int main()
{
//	interestRate = 0.0015;
	Account::rate(0.026);	

	Account a("张三", 1000);
	a.deposit(500);

	Account b("李四", 2000);
	b.deposit(600);	
	
	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;
	
	cout << a.rate() << endl;
	a.rate(0.018);
	cout << b.rate() << endl;

	Account::rate(0.02);
	a.applyint();
	b.applyint();
	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;	

	return 0;
}

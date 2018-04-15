#include <iostream>

using namespace std;

enum COLOR {Red, Green, Blue, Yellow, White, Black, Brown};

class Animal
{
public:
	Animal(int);
	virtual ~Animal() { cout << "Animal 析构函数被调用...\n"; }
	virtual int GetAge() const { return itsAge; }
	virtual void SetAge(int age) { itsAge = age; }
	virtual void Sleep() const = 0;
	virtual void Eat() const = 0;
	virtual void Reproduce() const = 0;
	virtual void Move() const = 0;
	virtual void Speak() const = 0;

private:
	int itsAge;
};

Animal::Animal(int age):itsAge(age)
{
	cout << "Animal 构造函数被调用...\n";
}


class Mammal : public Animal
{
public:
	Mammal(int age): Animal(age)
	{ cout << "Mamal 构造函数被调用...\n"; }
	virtual ~Mammal()
	{ cout << "Mamal 析构函数被调用...\n"; }
	virtual void Reproduce() const 
	{ cout << "Mamal reproduce depicted...\n"; }
};


class Fish: public Animal
{
public:
	Fish(int age): Animal(age){ cout << "Fish 构造函数被调用...\n"; }
	virtual ~Fish() { cout << "Fish 析构函数被调用...\n"; }
	virtual void Sleep() const { cout << "Fish snoring...\n"; }
	virtual void Eat() const { cout << "Fish feeding...\n"; }
	virtual void Reproduce() const { cout << "Fish laying eggs...\n"; }
	virtual void Move() const { cout << "Fish swimming...\n"; }
	virtual void Speak() const { cout << "Fish speak...\n"; }

};


class Horse : public Mammal
{
public:
	Horse(int age, COLOR color): Mammal(age), itsColor(color) { cout << "Horse 构造函数被调用...\n"; }
	virtual ~Horse() { cout << "Horse 析构函数被调用...\n"; }
	virtual void Speak() const { cout << "Whinny...\n"; }
	virtual void Sleep() const { cout << "Horse snoring...\n"; }
	virtual COLOR GetItsColor() const { return itsColor; }
	virtual void Eat() const { cout << "Horse feeding...\n"; }
	virtual void Move() const { cout << "Horse running...\n"; }
protected:
	COLOR itsColor;
};


class Dog: public Mammal
{
public:
	Dog(int age, COLOR color): Mammal(age), itsColor(color)
	{ cout << "Dog 构造函数被调用...\n"; }
	virtual ~Dog()
	{ cout << "Dog 析构函数被调用...\n"; }
	virtual void Speak() const { cout << "Whoff...\n"; }
	virtual void Sleep() const { cout << "Dog sleeping...\n"; }
	virtual void Eat() const { cout << "Dog eating...\n"; }
	virtual void Move() const { cout << "Dog running...\n"; }
	virtual void Reproduce() const
	{ cout << "Dogs reproducing...\n"; }
protected:
	COLOR itsColor;
};



int main()
{
	Animal *pAnim = 0;
	int choice;
	bool fQuit = false;
	while(fQuit == false)
	{
		cout << "(1)Dog	(2)Horse  (3)Fish  (0)Quit: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				pAnim = new Dog(5, Brown);
				break;
			case 2:
				pAnim = new Horse(4, Black);
				break;
			case 3:
				pAnim = new Fish(4);
				break;
			default:
				fQuit = true;
				break;
		}
		if(fQuit == false)
		{
			pAnim->Speak();
			pAnim->Eat();
			pAnim->Reproduce();
			pAnim->Move();
			pAnim->Sleep();
			delete pAnim;
			cout << endl;
		}
	}
	
	return 0;
}

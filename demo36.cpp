#include <iostream>

using namespace std;

class Shape
{
public:
	Shape(){}
   	virtual ~Shape(){}
	virtual double GetArea() = 0;		// 纯虚函数
	virtual double GetPerim() = 0;
	virtual void Draw() = 0;
};

/*
纯虚函数可以写，也可以不写
void Shape::Draw()
{
	cout << "Abstract drawing 方法！\n";
}
*/

class Circle: public Shape
{
public:
	Circle(int radius): itsRadius(radius) {}
	virtual ~Circle() {}
	double GetArea() { return 3.14 * itsRadius * itsRadius; }
	double GetPerim() { return 2 * 3.14 * itsRadius; }
	void Draw();
private:
	int itsRadius;
};

void Circle::Draw()
{ 
	cout << "Circle drawing rounting here!\n";
	// Shape::Draw();
}

class Rectangle: public Shape
{
public:
	Rectangle(int len, int width): itsWidth(width), itsLength(len){}
  	virtual ~Rectangle() {}
	double GetArea() { return itsLength * itsWidth; }
	double GetPerim() { return 2 * (itsWidth + itsLength); }
	virtual int GetLength() { return itsLength; }
	virtual int GetWidth() { return itsWidth; }
	void Draw();
private:
	int itsWidth;
protected:
	int itsLength;
};

void Rectangle::Draw()
{
	for(int i=0; i<itsWidth; ++i)
	{
		for(int j=0; j<itsLength; ++j)
			cout << "x ";
		cout << "\n";
	}
	// Shape::Draw();
}

class Square: public Rectangle
{
public:
	Square(int len);
	Square(int len, int width);
	virtual ~Square() {}
//	double GetPerim() { return 4 * GetLength(); }
	double GetPerim() { return 4 * itsLength; }
	double GetArea() { return GetLength() * GetLength(); }

};

Square::Square(int len): Rectangle(len, len) {}
Square::Square(int len, int width): Rectangle(len, width)
{
	if(GetLength() != GetWidth())
		cout << "Error, not a square... a Rectangle??\n";
}

int main()
{
//	Circle a(8);
//	a.Draw();
//	Rectangle b(10, 5);
//	b.Draw();
//	cout << endl;
//	Square c(8);
//	c.Draw();
	
	int choice;
	bool fQuit = false;
	Shape *sp;
	while(fQuit == false)
	{
		cout << "(1) Circle (2) Rectangle (3) Square (0) Quit: ";
		cin >> choice;
		switch(choice)
		{
			case 1:
				sp = new Circle(5);
				break;
			case 2:
				sp = new Rectangle(10, 5);
				break;
			case 3:
				sp = new Square(5);
				break;
			case 0:
				fQuit = true;
				break;
			default:
				cout << "unvalid number, try again!"<< endl;
    				break;
		}
		if(fQuit == false)
		{
			sp->Draw();
			delete sp;
			cout << endl;
		}
	}	
	return 0;
}



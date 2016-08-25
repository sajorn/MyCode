/*
	1. 设计立方体类(cube)，求出立方体的面积和体积
	求两个立方体，是否相等（全局函数和成员函数）
*/

#include <iostream>
using namespace std;

class Cube
{
public:
	void SetA(double a); //设长
	void SetB(double b); //设宽
	void SetC(double c); //设高
	void SetABC(double a, double b, double c);

	double GetA(); //得长
	double GetB(); //得宽
	double GetC(); //得高

	double GetArea(); //得面积
	double GetPerimeter(); //得周长

	void PrintCube(); //打印
	bool IsEqual(Cube &c); //判断两个立方体是否相等

private:
	double a_;
	double b_;
	double c_;
	double area_;
	double perimeter_;
};

void Cube::SetA(double a)
{
	a_ = a;
}

void Cube::SetB(double b)
{
	b_ = b;
}

void Cube::SetC(double c)
{
	c_ = c;
}

void Cube::SetABC(double a, double b, double c)
{
	a_ = a;
	b_ = b;
	c_ = c;
}

double Cube::GetA()
{
	return a_;
}

double Cube::GetB()
{
	return b_;
}

double Cube::GetC()
{
	return c_;
}

double Cube::GetArea()
{
	area_ = a_ * b_ * c_;
	return area_;
}

double Cube::GetPerimeter()
{
	perimeter_ = (a_ + b_ + c_) * 4;
	return perimeter_;
}

void Cube::PrintCube()
{
	cout << "Area = " << GetArea() << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
}

bool Cube::IsEqual(Cube &c)
{
	if (a_ == c.GetA() && b_ == c.GetB() && c_ == c.GetC())
	{
		return true;
	}
	return false;
}

int main1()
{
	Cube c1, c2, c3;
	c1.SetABC(1.0, 2.0, 3.0);
	c2.SetABC(1.0, 2.0, 4.0);
	c3.SetABC(1.0, 2.0, 3.0);

	if (c1.IsEqual(c2))
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}
	c1.PrintCube();
	c2.PrintCube();
	return 0;
}

/*---------------------------------*/

/*
	2.设计一个圆形类（AdvCircle），和一个点类（Point），计算点在圆内部还是圆外
	即：求点和圆的关系（圆内和圆外）
*/

//点类
class Point{
public:
	void SetPoint(double x, double y)
	{
		x_ = x;
		y_ = y;
	}

	double GetPointX()
	{
		return x_;
	}

	double GetPointY()
	{
		return y_;
	}

private:
	double x_;
	double y_;
};

//圆类
class Circle{
public:
	void SetCircle(double x, double y, double r)
	{
		x_ = x;
		y_ = y;
		r_ = r;
	}

	bool IsInCircle(Point& p)
	{
		double d;
		d = (p.GetPointX() - x_) * (p.GetPointX() - x_) +
			(p.GetPointY() - y_) * (p.GetPointY() - y_);
		if (d > (r_ * r_))
		{
			return false;
		}

		return true;
	}

private:
	double x_;
	double y_;
	double r_;
};

int main()
{
	Point p;
	Circle c;
	p.SetPoint(3, 0);
	c.SetCircle(0, 0, 3);
	
	if (c.IsInCircle(p))
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}

	return 0;
}
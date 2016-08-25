/*
	作业1：编写C++程序完成以下功能：
	1）定义一个Point类，其属性包括点的坐标，提供计算两点之间距离的方法；
	2）定义一个圆形类，其属性包括圆心和半径；
	3）创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，并输出结果。

	作业2：设计并测试一个名为Rectangle的矩形类，其属性为矩形的左下角与右上角两个点的坐标，
	根据坐标能计算出矩形的面积

	作业3：定义一个Tree类，有成员ages（树龄），成员函数grow（int years）对ages加上years，
	age（）显示tree对象的ages的值。

*/
#include <iostream>
#include <cmath>
using namespace std;

//坐标类
class Point{
public:
	void SetXY(double x, double y)
	{
		x_ = x;
		y_ = y;
	}

	double GetX()
	{
		return x_;
	}

	double GetY()
	{
		return y_;
	}

	double GetDistance(Point& p)
	{
		double d;
		d = (p.GetX() - x_) * (p.GetX() - x_) + (p.GetY() - y_) * (p.GetY() - y_);
		return sqrt(d);
	}

private:
	double x_;
	double y_;
};

class Circle{
public:
	void SetXYR(double x, double y, double r)
	{
		p_.SetXY(x, y);
		r_ = r;
	}
	//判断是否相交
	bool IsCross(Circle & c)
	{
		if ((c.r_ + r_) < p_.GetDistance(c.p_))
		{
			return false;
		}
		
		return true;
	}

private:
	double r_;
	Point p_; //圆心坐标
};

class Rectangle{
public:
	//矩形面积
	double GetArea()
	{
		double area = abs((pRight_.GetY() - pLeft_.GetY())) * abs((pRight_.GetX() - pLeft_.GetX()));
		return area;
	}

	void SetPLeft(double x, double y)
	{
		pLeft_.SetXY(x, y);
	}

	void SetPRight(double x, double y)
	{
		pRight_.SetXY(x, y);
	}

private:
	Point pLeft_; //左下角坐标
	Point pRight_; //右上角坐标
};

/*
	作业3：定义一个Tree类，有成员ages（树龄），成员函数grow（int years）对ages加上years，
	age（）显示tree对象的ages的值。
*/

class Tree{
public:
	Tree()
	{
		ages_ = 0;
	}

	void Grow(int years)
	{
		ages_ += years;
	}

	int Age()
	{
		return ages_;
	}

private:
	int ages_;
};

int main()
{
	//测试1
	Circle c1, c2;
	double x1, x2, y1, y2, r1, r2;
	cout << "c1圆心坐标: ";
	cin >> x1 >> y1;
	cout << "c1半径: ";
	cin >> r1;
	c1.SetXYR(x1, y1, r1);

	cout << "c2圆心坐标: ";
	cin >> x2 >> y2;
	cout << "c2半径: ";
	cin >> r2;
	c2.SetXYR(x2, y2, r2);

	if (c1.IsCross(c2))
	{
		cout << "相交" << endl;
	}
	else
	{
		cout << "不相交" << endl;
	}

	//测试2
	Rectangle r;
	double x3, y3, x4, y4;
	cout << "左下角坐标: ";
	cin >> x3 >> y3;
	r.SetPLeft(x3, y3);

	cout << "右上角坐标: ";
	cin >> x4 >> y4;
	r.SetPRight(x4, y4);

	double area = r.GetArea();
	cout << "Area = " << area << endl;

	//测试3
	int year;
	Tree t;
	cout << "输入时间: ";
	cin >> year;
	t.Grow(year);
	cout << "它今年" << t.Age() << "岁" << endl;

	return 0;
}

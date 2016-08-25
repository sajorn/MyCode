/*
	��ҵ1����дC++����������¹��ܣ�
	1������һ��Point�࣬�����԰���������꣬�ṩ��������֮�����ķ�����
	2������һ��Բ���࣬�����԰���Բ�ĺͰ뾶��
	3����������Բ�ζ�����ʾ�û�����Բ������Ͱ뾶���ж�����Բ�Ƿ��ཻ������������

	��ҵ2����Ʋ�����һ����ΪRectangle�ľ����࣬������Ϊ���ε����½������Ͻ�����������꣬
	���������ܼ�������ε����

	��ҵ3������һ��Tree�࣬�г�Աages�����䣩����Ա����grow��int years����ages����years��
	age������ʾtree�����ages��ֵ��

*/
#include <iostream>
#include <cmath>
using namespace std;

//������
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
	//�ж��Ƿ��ཻ
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
	Point p_; //Բ������
};

class Rectangle{
public:
	//�������
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
	Point pLeft_; //���½�����
	Point pRight_; //���Ͻ�����
};

/*
	��ҵ3������һ��Tree�࣬�г�Աages�����䣩����Ա����grow��int years����ages����years��
	age������ʾtree�����ages��ֵ��
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
	//����1
	Circle c1, c2;
	double x1, x2, y1, y2, r1, r2;
	cout << "c1Բ������: ";
	cin >> x1 >> y1;
	cout << "c1�뾶: ";
	cin >> r1;
	c1.SetXYR(x1, y1, r1);

	cout << "c2Բ������: ";
	cin >> x2 >> y2;
	cout << "c2�뾶: ";
	cin >> r2;
	c2.SetXYR(x2, y2, r2);

	if (c1.IsCross(c2))
	{
		cout << "�ཻ" << endl;
	}
	else
	{
		cout << "���ཻ" << endl;
	}

	//����2
	Rectangle r;
	double x3, y3, x4, y4;
	cout << "���½�����: ";
	cin >> x3 >> y3;
	r.SetPLeft(x3, y3);

	cout << "���Ͻ�����: ";
	cin >> x4 >> y4;
	r.SetPRight(x4, y4);

	double area = r.GetArea();
	cout << "Area = " << area << endl;

	//����3
	int year;
	Tree t;
	cout << "����ʱ��: ";
	cin >> year;
	t.Grow(year);
	cout << "������" << t.Age() << "��" << endl;

	return 0;
}

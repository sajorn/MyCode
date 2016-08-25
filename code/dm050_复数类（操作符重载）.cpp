#include <iostream>

using namespace std;

//复数类
class CComplex{
public:
	CComplex()
	{
		m_x = 0;
		m_y = 0;
	}
	CComplex(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	~CComplex() {}
	//打印
	void PrintComplex()
	{
		if (m_y > 0)
		{
			cout << m_x << "+" << m_y << "i" << endl;
		}
		else
		{
			cout << m_x << "-" << -m_y << "i" << endl;
		}
	}

	//重载+
	CComplex operator+(CComplex& c)
	{
		CComplex cTmpComplex(*this); //通过*this指针初始化临时对象
		cTmpComplex.m_x += c.m_x;
		cTmpComplex.m_y += c.m_y;
		return cTmpComplex;
	}

	//全局函数重载前置++
	friend CComplex& operator++(CComplex& c);

	//全局函数重载后置++，占位符只为了区别前置++，不起任何作用
	friend CComplex operator++(CComplex& c, int);
	
	//成员函数重载前置--
	CComplex& operator--()
	{
		m_x--;
		m_y--;
		return *this; //将this指向的对象结果返回
	}

	//成员函数重载前置--
	CComplex operator--(int)
	{
		CComplex tmp(*this);
		--(*this);
		return tmp;
	}

private:
	int m_x;
	int m_y;
};

CComplex& operator++(CComplex& c)
{
	c.m_x++;
	c.m_y++;
	return c;
}

CComplex operator++(CComplex& c, int)
{
	CComplex tmp(c);
	++c;
	return tmp;
}

int main()
{
	CComplex c1(1, 2);
	CComplex c2(2, 3);
	c1 = c1 + c2;
	c1.PrintComplex();
	c2++;
	c2.PrintComplex();
	c2--;
	c2.PrintComplex();
	return 0;
}
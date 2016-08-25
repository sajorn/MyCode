#include <iostream>

using namespace std;

//������
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
	//��ӡ
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

	//����+
	CComplex operator+(CComplex& c)
	{
		CComplex cTmpComplex(*this); //ͨ��*thisָ���ʼ����ʱ����
		cTmpComplex.m_x += c.m_x;
		cTmpComplex.m_y += c.m_y;
		return cTmpComplex;
	}

	//ȫ�ֺ�������ǰ��++
	friend CComplex& operator++(CComplex& c);

	//ȫ�ֺ������غ���++��ռλ��ֻΪ������ǰ��++�������κ�����
	friend CComplex operator++(CComplex& c, int);
	
	//��Ա��������ǰ��--
	CComplex& operator--()
	{
		m_x--;
		m_y--;
		return *this; //��thisָ��Ķ���������
	}

	//��Ա��������ǰ��--
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
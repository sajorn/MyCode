/*
	复数的模板类实现
*/

#include <iostream>
using namespace std;

//滥用友元函数时的前置声明，在.cpp和.h分开时无法实现
//关注点
template <typename T>
class cComplex;
template <typename T>
cComplex<T> ComplexSub(cComplex<T> &refCom1, cComplex<T> &refCom2);

template <typename T>
class cComplex
{
public:
	cComplex(T a = 0, T b = 0);
	~cComplex();
	cComplex(cComplex& refCom);

	//+ -
	cComplex operator+(cComplex &refCom);
	cComplex operator-(cComplex &refCom);

	//<< >>
	friend ostream& operator<< <T> (ostream& os, cComplex &refCom);
	friend istream& operator>> <T> (istream& is, cComplex &refCom);
	
	//滥用友元函数实现相减
	//关注点
	friend cComplex<T> ComplexSub<T>(cComplex<T> &refCom1, cComplex<T> &refCom2);
private:
	T m_a;
	T m_b;
};

template <typename T>
cComplex<T>::cComplex(T a, T b)
{
	m_a = a;
	m_b = b;
}

template <typename T>
cComplex<T>::cComplex(cComplex<T>& refCom)
{
	m_a = refCom.m_a;
	m_b = refCom.m_b;
}

template <typename T>
cComplex<T>::~cComplex()
{
	m_a = 0;
	m_b = 0;
}

template <typename T>
cComplex<T> cComplex<T>::operator+(cComplex<T> &refCom)
{
	cComplex tmpCom(m_a + refCom.m_a, m_b + refCom.m_b);
	return tmpCom;
}

template <typename T>
cComplex<T> cComplex<T>::operator-(cComplex<T> &refCom)
{
	cComplex tmpCom(m_a - refCom.m_a, m_b - refCom.m_b);
	return tmpCom;
}

template <typename T>
ostream& operator<<(ostream &os, cComplex<T> &refCom)
{
	if (refCom.m_b > 0)
	{
		os << refCom.m_a << " + " << refCom.m_b << "i";
	}
	else
	{
		os << refCom.m_a << " - " << -refCom.m_b << "i";
	}
	return os;
}

template <typename T>
istream& operator>>(istream &is, cComplex<T> &refCom)
{
	is >> refCom.m_a >> refCom.m_b;
	return is;
}

template <typename T>
cComplex<T> ComplexSub(cComplex<T> &refCom1, cComplex<T> &refCom2)
{
	//关注点
	cComplex<int> tmp(refCom1.m_a - refCom2.m_a, refCom1.m_b - refCom2.m_b);
	return tmp;
}

int main()
{
	cComplex<int> cInt1(1, 2);
	cComplex<int> cInt2(2, 3);
	cComplex<double> cDouble1(2.3, 3.5);
	cComplex<double> cDouble2(3.2, 3.3);
	cInt1 = cInt1 - cInt2;
	cout << cInt1 << endl;
	cDouble1 = cDouble1 + cDouble2;
	cout << cDouble1 << endl;
	cout << ComplexSub<int>(cInt1, cInt2) << endl;
	
	return 0;
}
/*
	单个类模板的定义和使用
	普通类继承类模板的定义和使用
	类模板继承类模板的定义和使用
*/

#include <iostream>
using namespace std;

//单个模板类
template <typename T>
class A
{
public:
	A(T a = 0)
	{
		m_a = a;
		m_sCount++;
	}
	~A()
	{
		m_a = 0;
	}
	void PrintA()
	{
		cout << "a = " << m_a << ", count = " << m_sCount << endl;
	}
private:
	T m_a;
	static int m_sCount;
};

//普通类继承类模板，需要具体化类模板告诉编译器分配具体的内存
class B :public A<int>
{
public:
	B(int a = 0, int b = 0) :A<int>(a)
	{
		m_b = b;
	}
	~B()
	{
		m_b = 0;
	}
	void PrintAB()
	{
		PrintA();
		cout << "b = " << m_b << endl;
	}
private:
	int m_b;
};

//类模板继承类模板
template <typename T>
class C :public A<T>
{
public:
	C(T a = 0, T c = 0) :A<T>(a)
	{
		m_c = c;
	}
	~C()
	{
		m_c = 0;
	}
	void PrintAC()
	{
		PrintA();
		cout << "c = " << m_c << endl;
	}
private:
	T m_c;
};

template <typename T>
int A<T>::m_sCount = 0;

int main()
{
	A<int> a(10);
	a.PrintA();
	A<double> a1(10.5);
	a1.PrintA();
	A <int> a2(11);
	a2.PrintA();
// 	B b(1, 3);
// 	b.PrintAB();
// 	cout << "----华丽的分割线----" << endl;
// 	C<int> c(1, 2);
// 	C<double> c1(2.1, 3.2);
// 	c.PrintAC();
// 	c1.PrintAC();
	return 0;
}
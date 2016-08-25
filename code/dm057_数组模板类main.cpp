/*
	实现数组模板类，能存取int char cTeacher cTeacher*
	其中cTeacher类中如果是带指针需要分配内存的时候需要重写拷贝构造等号和输出运算符
*/

#include "dm057_TArray.hpp"
#include "memwatch.h"
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class cTeacher
{
public:
	cTeacher()
	{
		m_age = 0;
		m_name = nullptr;
	}
	cTeacher(const char* pName, const int age)
	{
		m_name = new char[strlen(pName) + 1];
		strcpy(m_name, pName);
		m_age = age;
	}
	cTeacher(cTeacher& refTea)
	{
		m_name = new char[strlen(refTea.m_name) + 1];
		strcpy(m_name, refTea.m_name);
		m_age = refTea.m_age;
	}
	~cTeacher()
	{
		if (m_name != nullptr)
		{
			delete[] m_name;
			m_name = nullptr;
		}
		m_age = 0;
	}
	cTeacher& operator=(cTeacher& refTea)
	{
		if (m_name != nullptr)
		{
			delete[] m_name;
			m_name = nullptr;
		}
		m_name = new char[strlen(refTea.m_name) + 1];
		strcpy(m_name, refTea.m_name);
		m_age = refTea.m_age;
		return *this;
	}
	friend ostream& operator<<(ostream& os, cTeacher& refTea)
	{
		os << "Name: " << refTea.m_name << ", Age: " << refTea.m_age;
		return os;
	}
	friend istream& operator>>(istream& is, cTeacher& refTea)
	{
		char tmpName[256] = { 0 };
		cout << "Name: ";
		is >> tmpName;
		refTea.m_name = new char[strlen(tmpName) + 1];
		strcpy(refTea.m_name, tmpName);
		cout << "Age: ";
		is >> refTea.m_age;
		return is;
	}
private:
	int m_age;
	char* m_name;
};

int main()
{
	cTeacher t1, t2;
	cin >> t1;
	t2 = t1;

	TArray<cTeacher> t(2);
	t[0] = t1;
	t[1] = t2;
	cout << t << endl;
	return 0;
}
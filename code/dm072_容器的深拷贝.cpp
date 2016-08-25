/*
	容器内部是值拷贝，因此有指针分配内存时需要重写
	无参构造函数
	拷贝构造函数
	等号操作符重载
*/

#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

class cStudent
{
public:
	cStudent()
	{
		m_name = new char;
		m_name[0] = '\0';
		m_age = 0;
	}
	cStudent(const cStudent& refStu)
	{
		m_name = new char[strlen(refStu.m_name) + 1];
		strcpy(m_name, refStu.m_name);
		m_age = refStu.m_age;
	}
	~cStudent()
	{
		if (m_name)
		{
			delete[] m_name;
			m_name = nullptr;
		}
		m_age = 0;
	}

	cStudent(char* pName, int nAge)
	{
		m_name = new char[strlen(pName) + 1];
		strcpy(m_name, pName);
		m_age = nAge;
	}

	cStudent& operator=(const cStudent& refStu)
	{
		m_name = new char[strlen(refStu.m_name) + 1];
		strcpy(m_name, refStu.m_name);
		m_age = refStu.m_age;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const cStudent& refStu)
	{
		os << "Name: " << refStu.m_name << "\t Age: " << refStu.m_age;
		return os;
	}

private:
	char* m_name;
	int m_age;
};

int main()
{
	cStudent s1("John", 33);
	cStudent s2("Mike", 34);
	
	vector<cStudent> v;
	v.push_back(s1);
	v.push_back(s2);

	for (vector<cStudent>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
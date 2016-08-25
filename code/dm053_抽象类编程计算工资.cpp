#include <iostream>
#pragma warning(disable:4996)
using namespace std;

//工资接口
class iSalary
{
public:
	virtual void PrintSal() = 0;
};

//程序员
class cProgramer
{
public:
	cProgramer()
	{
		m_name = nullptr;
		m_salary = 0;
	}
	cProgramer(const char* name, int salary)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_salary = salary;
	}
	~cProgramer()
	{
		if (m_name)
		{
			delete[] m_name;
			m_name = nullptr;
		}
		m_salary = 0;
	}
protected:
	char* m_name;
	int m_salary;
};

//初级的
class cJunior :public cProgramer, public iSalary
{
public:
	cJunior()
	{

	}
	cJunior(const char* name, int salary) :cProgramer(name, salary)
	{

	}
	~cJunior()
	{

	}
	void PrintSal()
	{
		cout << "初级的: " << endl;
		cout << "Name: " << m_name << endl;
		cout << "Salary: " << m_salary << endl;
	}
};

//中级的
class cMiddle :public cProgramer, public iSalary
{
public:
	cMiddle()
	{

	}
	cMiddle(const char* name, int salary) :cProgramer(name, salary)
	{

	}
	~cMiddle()
	{

	}
	void PrintSal()
	{
		cout << "中级的: " << endl;
		cout << "Name: " << m_name << endl;
		cout << "Salary: " << m_salary << endl;
	}
};

//高级的
class cAdvanced :public cProgramer, public iSalary
{
public:
	cAdvanced()
	{

	}
	cAdvanced(const char* name, int salary) :cProgramer(name, salary)
	{

	}
	~cAdvanced()
	{

	}
	void PrintSal()
	{
		cout << "高级的: " << endl;
		cout << "Name: " << m_name << endl;
		cout << "Salary: " << m_salary << endl;
	}
};

void Print(iSalary* i)
{
	i->PrintSal();
}

int main()
{
	cJunior j1("aa", 1000);
	cMiddle m1("bb", 2000);
	cAdvanced a1("cc", 3000);
	Print(&j1);
	Print(&m1);
	Print(&a1);
	return 0;
}
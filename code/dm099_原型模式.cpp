//一个复杂的对象，实现复制对象，统一一个接口
#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class CPerson
{
public:
	virtual void Print() = 0;
	virtual CPerson* Clone() = 0;
};

class CPlusProgram : public CPerson
{
public:
	CPlusProgram()
	{
		m_name = new char;
		m_name[0] = '\0';
		m_age = 0;
	}
	CPlusProgram(char* name, int age)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		m_age = age;
	}
	~CPlusProgram()
	{
		if (m_name)
		{
			delete m_name;
			m_name = nullptr;
		}
	}
	void Print()
	{
		cout << "name: " << m_name << ", age: " << m_age << endl;
	}
	CPerson* Clone()
	{
		CPlusProgram* tPerson = new CPlusProgram;
		if (tPerson->m_name)
		{
			delete tPerson->m_name;
		}
		tPerson->m_name = new char[strlen(m_name) + 1];
		strcpy(tPerson->m_name, m_name);
		tPerson->m_age = m_age;
		return tPerson;
	}
private:
	char* m_name;
	int m_age;
};

int main()
{
	CPerson* person = new CPlusProgram("Kitty", 40);
	person->Print();
	CPerson* person2 = person->Clone();
	person2->Print();
	return 0;
}
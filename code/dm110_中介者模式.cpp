#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

class Mediator;

class Person
{
public:
	Person(string name, int sex, int condition, Mediator* mediator)
	{
		m_name = name;
		m_sex = sex;
		m_condition = condition;
		m_mediator = mediator;
	}
	int GetSex()
	{
		return m_sex;
	}
	int GetCondition()
	{
		return m_condition;
	}
	virtual void SetParent(Person* person) = 0;
protected:
	string m_name;
	int m_sex;
	int m_condition;
	Mediator* m_mediator;
};

class Mediator
{
public:
	void GetMan(Person* man)
	{
		m_man = man;
	}
	void GetWoman(Person* woman)
	{
		m_woman = woman;
	}
	void SetParent()
	{
		if (m_man->GetSex() == m_woman->GetSex())
		{
			cout << "¾Ü¾øÍ¬ÐÔÁµ" << endl;
		}
		else if (m_man->GetCondition() == m_woman->GetCondition())
		{
			cout << "²»Åä" << endl;
		}
		else
		{
			cout << "Åä" << endl; 
		}
	}
private:
	Person* m_man;
	Person* m_woman;
};



class Man : public Person
{
public:
	Man(string name, int sex, int condition, Mediator* mediator) 
		: Person(name, 0, condition, mediator)
	{

	}
	void SetParent(Person* persons)
	{
		m_mediator->GetMan(this);
		m_mediator->GetWoman(persons);
		m_mediator->SetParent();
	}
};

class Woman : public Person
{
public:
	Woman(string name, int sex, int condition, Mediator* mediator)
		: Person(name, 1, condition, mediator)
	{

	}
	void SetParent(Person* persons)
	{
		m_mediator->GetMan(persons);
		m_mediator->GetWoman(this);
		m_mediator->SetParent();
	}
};

int main()
{
	Mediator* mediator = new Mediator;
	Person* woman = new Woman("John", 1, 11, mediator);
	Person* man1 = new Man("Mike", 0, 12, mediator);
	Person* man2 = new Man("Kite", 0, 11, mediator); 

	mediator->GetMan(man1);
	mediator->GetWoman(woman);
	mediator->SetParent();

	mediator->GetMan(man2);
	mediator->GetWoman(woman);
	mediator->SetParent();

	delete mediator;
	delete woman;
	delete man1;
	delete man2;

	return 0;
}
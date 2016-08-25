#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;

class Person;

class Reserve
{
public:
	Reserve(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string GetName()
	{
		return m_name;
	}
	int GetAge()
	{
		return m_age;
	}
private:
	string m_name;
	int m_age;
};

class Person
{
public:
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	void SetName(string name)
	{
		m_name = name;
	}
	void SetAge(int age)
	{
		m_age = age;
	}
	string GetName()
	{
		return m_name;
	}
	int GetAge()
	{
		return m_age;
	}

	Reserve* CreateReserve()
	{
		return new Reserve(m_name, m_age);
	}

	void Recover(Reserve* reserve)
	{
		m_name = reserve->GetName();
		m_age = reserve->GetAge();
	}

	void Print()
	{
		cout << "Name: " << m_name << ", Age: " << m_age << endl;
	}
private:
	string m_name;
	int m_age;
};

class CareTaker
{
public:
	CareTaker(Reserve* reserve)
	{
		m_reserve = reserve;
	}
	Reserve* GetReserve()
	{
		return m_reserve;
	}
	void SetReserve(Reserve* reserve)
	{
		m_reserve = reserve;
	}
private:
	Reserve* m_reserve;
};

int main()
{
	CareTaker* careTaker = NULL;
	Reserve* reserve = NULL;
	Person* man = new Person("Jack", 10);
	man->Print();

	cout << "Revise Age: " << endl;
	careTaker = new CareTaker(man->CreateReserve());
	man->SetAge(20);
	man->Print();
	
	cout << "Recover Age: " << endl;
	man->Recover(careTaker->GetReserve());
	man->Print();

	delete careTaker;
	delete reserve;
	delete man;
	return 0;
}
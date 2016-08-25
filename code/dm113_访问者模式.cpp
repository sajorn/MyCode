#include <iostream>
#include <string>
#include <list>
#pragma warning(disable:4996)
using namespace std;

class ParkElem;

class Visitor
{
public:
	virtual void DoWork(ParkElem* parkElem) = 0;
};

class ParkElem
{
public:
	ParkElem(string name)
	{
		m_name = name;
	}
	string GetPark()
	{
		return m_name;
	}
	virtual void Accept(Visitor* visitor) = 0;
private:
	string m_name;
};

class VisitorA : public Visitor
{
public:
	void DoWork(ParkElem* parkElem)
	{
		cout << parkElem->GetPark() << " 已打扫" << endl;
	}
};

class VisitorB : public Visitor
{
public:
	void DoWork(ParkElem* parkElem)
	{
		cout << parkElem->GetPark() << " 已打扫" << endl;
	}
};

class ParkA : public ParkElem
{
public:
	ParkA(string name) : ParkElem(name)
	{

	}
	void Accept(Visitor* visitor)
	{
		visitor->DoWork(this);
	}
};

class ParkB : public ParkElem
{
public:
	ParkB(string name) : ParkElem(name)
	{

	}
	void Accept(Visitor* visitor)
	{
		visitor->DoWork(this);
	}
};

class Park : public ParkElem
{
public:
	Park() : ParkElem("Whole")
	{
		m_park.clear();
	}
	void SetParkElem(ParkElem* parkElem)
	{
		m_park.push_back(parkElem);
	}
	void Accept(Visitor* visitor)
	{
		for (list<ParkElem*>::iterator it = m_park.begin(); it != m_park.end(); ++it)
		{
			(*it)->Accept(visitor);
		}
	}
private:
	list<ParkElem*> m_park;
};

class Manager : public Visitor
{
public:
	void DoWork(ParkElem* parkElem)
	{
		cout << "管理者巡视各个部分" << endl;
	}
};

int main()
{
	Visitor* manager = new Manager;
	ParkA* parkA = new ParkA("Kim Park");
	ParkB* parkB = new ParkB("Jack Park");

	Park* park = new Park;
	park->SetParkElem(parkA);
	park->SetParkElem(parkB);

	park->Accept(manager);

	return 0;
}
#include <iostream>
#include <list>
#pragma warning(disable:4996)
using namespace std;

class Secretary;

class Observer
{
public:
	Observer(Secretary* secretary)
	{
		m_secretary = secretary;
	}
	void Update(const char* str)
	{
		cout << str << endl;
	}

private:
	Secretary* m_secretary;
};

class Secretary
{
public:
	Secretary()
	{
		m_sList.clear();
	}
	void Notify(const char* str)
	{
		for (list<Observer*>::iterator it = m_sList.begin(); it != m_sList.end(); ++it)
		{
			(*it)->Update(str);
		}
	}
	void SetObsever(Observer* observer)
	{
		m_sList.push_back(observer);
	}
private:
	list<Observer*> m_sList;
};

int main()
{
	Secretary* secretary = new Secretary;
	Observer* observer1 = new Observer(secretary);
	Observer* observer2 = new Observer(secretary);

	secretary->SetObsever(observer1);
	secretary->SetObsever(observer2);

	secretary->Notify("Boss comes");
	secretary->Notify("Boss leaves");

	delete secretary;
	delete observer1;
	delete observer2;

	return 0;
}
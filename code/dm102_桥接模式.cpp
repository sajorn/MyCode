#include <iostream>
using namespace std;

class Enginee
{
public:
	virtual void InstallEnginee() = 0;
};

class Enginee1200cc : public Enginee
{
public:
	void InstallEnginee()
	{
		cout << "Install Enginee 1200cc" << endl;
	}
};

class Enginee2400cc : public Enginee
{
public:
	void InstallEnginee()
	{
		cout << "Install Engine 2400cc" << endl; 
	}
};

class Car
{
public:
	Car(Enginee* enginee)
	{
		m_enginee = enginee;
	}
	virtual void show() = 0;
protected:
	Enginee* m_enginee;
};

class BMW5 : public Car
{
public:
	BMW5(Enginee* enginee) : Car(enginee)
	{

	}
	void show()
	{
		cout << "BMW5: ";
		m_enginee->InstallEnginee();
	}
};

class BMW6 : public Car
{
public:
	BMW6(Enginee* enginee) : Car(enginee)
	{

	}
	void show()
	{
		cout << "BMW6: ";
		m_enginee->InstallEnginee();
	}
};

int main()
{
	Enginee* enginee = new Enginee1200cc;
	Car* car = new BMW6(enginee);
	car->show();
	return 0;
}
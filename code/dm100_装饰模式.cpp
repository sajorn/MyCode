//自由增加新功能
#include <iostream>
using namespace std;

class Car 
{
public:
	virtual void show() = 0;
};

class RunCar : public Car
{
public:
	void show() override
	{
		cout << "I can Run" << endl;
	}
};

class SwimCar : public Car
{
public:
	SwimCar(Car* car)
	{
		m_car = car;
	}
	void show()
	{
		m_car->show();
		cout << "I can Swim" << endl;
	}
private:
	Car* m_car;
};

class FlyCar : public Car
{
public:
	FlyCar(Car* car)
	{
		m_car = car;
	}
	void show()
	{
		m_car->show();
		cout << "I can Fly" << endl;
	}
private:
	Car* m_car;
};

int main()
{
	Car* runCar = new RunCar;
	runCar->show();
	cout << "---" << endl;
	Car* swimCar = new SwimCar(runCar);
	swimCar->show();
	cout << "---" << endl;
	Car* flyCar = new FlyCar(swimCar);
	flyCar->show();
	return 0;
}
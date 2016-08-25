#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;

	void Make()
	{
		MakeHead();
		MakeBody();
		MakeTail();
	}
};

class MakeBus : public MakeCar
{
public:
	void MakeHead()
	{
		cout << "Bus Head" << endl;
	}
	void MakeBody()
	{
		cout << "Bus Body" << endl;
	}
	void MakeTail()
	{
		cout << "Bus Tail" << endl;
	}
};

class MakeJeep : public MakeCar
{
public:
	void MakeHead()
	{
		cout << "Jeep Head" << endl;
	}
	void MakeBody()
	{
		cout << "Jeep Body" << endl;
	}
	void MakeTail()
	{
		cout << "Jeep Tail" << endl;
	}
};

int main()
{
	MakeCar* car = new MakeBus;
	car->Make();
	delete car;
	car = new MakeJeep;
	car->Make();
	delete car;
	return 0;
}
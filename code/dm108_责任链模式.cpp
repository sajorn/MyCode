#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class CarHandle
{
public:
	virtual void HandleCar() = 0;
	void SetNextHandle(CarHandle* carHandle)
	{
		m_carHandle = carHandle;
	}
protected:
	CarHandle* m_carHandle;
};

class HeadHandle : public CarHandle
{
public:
	void HandleCar()
	{
		cout << "Make Head" << endl;
		if (m_carHandle != NULL)
		{
			m_carHandle->HandleCar();
		}
	}
};

class BodyHandle : public CarHandle
{
public:
	void HandleCar()
	{
		cout << "Make Body" << endl;
		if (m_carHandle != NULL)
		{
			m_carHandle->HandleCar();
		}
	}
};

class TailHandle : public CarHandle
{
public:
	void HandleCar()
	{
		cout << "Make Tail" << endl;
		if (m_carHandle != NULL)
		{
			m_carHandle->HandleCar();
		}
	}
};

int main()
{
	CarHandle* headHandle = new HeadHandle;
	CarHandle* bodyHandle = new BodyHandle;
	CarHandle* tailHandle = new TailHandle; 

	headHandle->SetNextHandle(bodyHandle);
	bodyHandle->SetNextHandle(tailHandle);
	tailHandle->SetNextHandle(NULL);

	headHandle->HandleCar();

	delete headHandle;
	delete tailHandle;
	delete bodyHandle;

	return 0;
}
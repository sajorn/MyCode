#include <iostream>
using namespace std;

class CFruit
{
public:
	virtual void GetFruit()
	{
		cout << "Fruit" << endl;
	}
};

class CPear :public CFruit
{
public:
	virtual void GetFruit()
	{
		cout << "Pear" << endl;
	}
};

class CBanana :public CFruit
{
public:
	virtual void GetFruit()
	{
		cout << "Banana" << endl; 
	}
};

//依赖关系
class Factory
{
public:
	CFruit* NewFruit(const char* name)
	{
		if (strcmp(name, "Banana") == 0)
		{
			return new CBanana;
		}
		else
		{
			return new CPear;
		}
	}
};

//改进版工厂模式
class CAdvFactory
{
public:
	virtual CFruit* AdvFruit()
	{
		return new CFruit;
	}
};

class CAdvBananaFactory : public CAdvFactory
{
public:
	virtual CFruit* AdvFruit()
	{
		return new CBanana;
	}
};

class CAdvPearFactory : public CAdvFactory
{
public:
	virtual CFruit* AdvFruit()
	{
		return new CPear;
	}
};

int main()
{
	Factory* factory = new Factory;
	CFruit* fruit = factory->NewFruit("Pear");
	fruit->GetFruit();
	fruit = factory->NewFruit("Banana");
	fruit->GetFruit();
	delete factory;
	delete fruit;
	cout << "---Adv---" << endl;

	CAdvFactory* advBananaFactory = new CAdvBananaFactory;
	CAdvFactory* advPearFactory = new CAdvPearFactory;
	CFruit* advFruit = advBananaFactory->AdvFruit();
	advFruit->GetFruit();
	advFruit = advPearFactory->AdvFruit();
	advFruit->GetFruit();
	delete advBananaFactory;
	delete advPearFactory;
	delete advFruit;
	return 0;
}
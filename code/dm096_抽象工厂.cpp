#include <iostream>
using namespace std;

//fruit class
class CFruit
{
public:
	virtual void GetName() = 0;
};

//factory class
class CFactory
{
public:
	virtual CFruit* GetBanana() = 0;
	virtual CFruit* GetApple() = 0;
};

//south apple
class CSouthApple : public CFruit
{
public:
	void GetName()
	{
		cout << "South Apple" << endl;
	}
};

//south banana
class CSouthBanana : public CFruit
{
public:
	void GetName()
	{
		cout << "South Banana" << endl;
	}
};

//north apple
class CNorthApple : public CFruit
{
public:
	void GetName()
	{
		cout << "North Apple" << endl;
	}
};

//north banana
class CNorthBanana : public CFruit
{
public:
	void GetName()
	{
		cout << "North Banana" << endl;
	}
};

//south factory
class CSouthFactory : public CFactory
{
public:
	CFruit* GetBanana()
	{
		return new CSouthBanana;
	}
	CFruit* GetApple()
	{
		return new CSouthApple;
	}
};

//north factory
class CNorthFactory : public CFactory
{
public:
	CFruit* GetBanana()
	{
		return new CNorthBanana;
	}
	CFruit* GetApple()
	{
		return new CNorthApple;
	}
};

int main()
{
	CFactory* southFactory = new CSouthFactory;
	CFactory* northFactory = new CNorthFactory;
	CFruit* southApple = southFactory->GetApple();
	CFruit* southBanana = southFactory->GetBanana();
	CFruit* northApple = northFactory->GetApple(); 
	CFruit* northBanana = northFactory->GetBanana();
	southApple->GetName();
	southBanana->GetName();
	northApple->GetName();
	northBanana->GetName();


	delete southFactory;
	delete northFactory;
	delete southApple; 
	delete southBanana;
	delete northApple;
	delete northBanana;
	return 0;
}
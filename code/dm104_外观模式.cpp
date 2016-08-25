#include <iostream>
using namespace std;

class SubSystemA
{
public:
	void show()
	{
		cout << "subA" << endl;
	}
};

class SubSystemB
{
public:
	void show()
	{
		cout << "subB" << endl;
	}
};

class SubSystemC
{
public:
	void show()
	{
		cout << "subC" << endl;
	}
};

class Facade
{
public:
	Facade()
	{
		m_a = new SubSystemA;
		m_b = new SubSystemB;
		m_c = new SubSystemC;
	}
	~Facade()
	{
		delete m_a;
		delete m_b;
		delete m_c;
	}
	void show()
	{
		m_a->show();
		m_b->show();
		m_c->show();
	}
private:
	SubSystemA* m_a;
	SubSystemB* m_b; 
	SubSystemC* m_c;
};

int main()
{
	Facade* test = new Facade;
	test->show();
	return 0;
}
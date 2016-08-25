#include <iostream>
using namespace std;

class Use18V
{
public:
	virtual void use18V() = 0;
};

class Use220V
{
public:
	void use220V()
	{
		cout << "Use 220V" << endl;
	}
};

class Adapter : public Use18V
{
public:
	Adapter(Use220V* use220v)
	{
		m_use220v = use220v;
	}
	void use18V()
	{
		m_use220v->use220V();
	}
private:
	Use220V* m_use220v;
};

int main()
{
	Use220V* use220v = new Use220V;
	Adapter* adapter = new Adapter(use220v);
	adapter->use18V();

	return 0;
}
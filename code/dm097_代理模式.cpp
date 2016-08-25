#include <iostream>
using namespace std;

class CBookStore
{
public:
	virtual void SaleBook()
	{
		cout << "Sale Book" << endl;
	}
};

class CRealBookStore
{
public:
	void SaleBook() //可以增加自己的业务逻辑
	{
		CBookStore bookStore;
		bookStore.SaleBook();
		Eleven();
	}
	void Eleven()
	{
		cout << "打折" << endl;
	}
};

int main()
{
	CRealBookStore* DangDangStore = new CRealBookStore;
	DangDangStore->SaleBook();
	return 0;
}
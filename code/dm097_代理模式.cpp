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
	void SaleBook() //���������Լ���ҵ���߼�
	{
		CBookStore bookStore;
		bookStore.SaleBook();
		Eleven();
	}
	void Eleven()
	{
		cout << "����" << endl;
	}
};

int main()
{
	CRealBookStore* DangDangStore = new CRealBookStore;
	DangDangStore->SaleBook();
	return 0;
}
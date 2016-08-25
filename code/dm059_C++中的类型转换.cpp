/*
	const_cast<>(): �Ƴ�������
	dynamic_cast<>(): ������֮���̬������ת��
	static_cast<>(): ����м�����ʽ����ת��
	reinterpreter_cast<>(): ���½������ͣ�ǿ���Ե�����ת��,ʲô���Ͷ���ǿת
*/

#include <iostream>
using namespace std;

class cAnimal
{
public:
	virtual void Bark() = 0;
};

class cDogs :public cAnimal
{
public:
	void Bark()
	{
		cout << "����" << endl;
	}
};

class cCats :public cAnimal
{
public:
	void Bark()
	{
		cout << "����" << endl;
	}
};

void WhoBark(cAnimal* animal)
{
	cDogs* pDogs = dynamic_cast<cDogs*>(animal); //����֪���������ĸ����࣬���Ǹ������򷵻ؿ�
	if (pDogs != nullptr)
	{
		pDogs->Bark();
	}

	cCats* pCats = dynamic_cast<cCats*>(animal);
	if (pCats != nullptr)
	{
		pCats->Bark();
	}
}

int main()
{
	double x = 3.5;
	int y = static_cast<int>(x); //�൱��C���Ե� int y = (int)x;
	cout << y << endl;
	cout << "-------" << endl;
	const char* p = "hello";
	char* p1 = const_cast<char*>(p); //���Խ�const����������const�����ǲ������޸�
	//p1[0] = 'b'; //������
	cout << p1 << endl;
	cout << "-------" << endl;
	cDogs dog1;
	cCats cat1;
	WhoBark(&dog1);
	WhoBark(&cat1);
	return 0;
}
#include <iostream>

using namespace std;

class Test{
public:
	Test(int a = 0)
	{
		a_ = a;
		cout << "���ù��캯��" << endl;
	}
	~Test()
	{
		cout << "������������" << endl;
	}
	Test(const Test& obj)
	{
		a_ = obj.a_ + 10;
	}
private:
	int a_;
};

void Print(Test tmp)//ʵ�δ����β�ʱ�����һ�ο������캯����������������tmp����
{
	cout << "��ӡtmp" << endl;
}

Test GetTest()
{
	Test tmp(4);
	return tmp; //���ص�����������ԭ��������
}

int main()
{
	Test t1 = 1; //��һ�ֵ���
	Test t2(2); //�ڶ��ֵ���

	Test t3;//�����ֵ���
	Print(t3);

	Test t4 = GetTest(); //��������ֱ��ת������������
	Test t5;
	t5 = GetTest(); //���������󿽱���t5����Ȼ����������������

	return 0;
}
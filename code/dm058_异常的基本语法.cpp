/*
	�쳣�Ļ����﷨����throw�׳��쳣����catch��׽�쳣��Ҳ���Բ�׽��������������׳�
*/

#include <iostream>
using namespace std;

void Divide(int x, int y)
{
	if (y == 0)
	{
		throw y; //������y�׳�
	}
	cout << "x / y = " << x / y << endl;
}

int main()
{
	try
	{
		Divide(10, 2);
		Divide(100, 0);
	}
	catch (int e) //��׽���������͵��쳣
	{
		cout << e << "����������" << endl;
		//throw; //Ҳ���Բ������������
	}
	catch (...) //��׽�����س�������������쳣
	{
		cout << "δ֪����" << endl;
	}

	return 0;
}
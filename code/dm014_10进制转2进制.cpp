/*
	10����ת����2������
	ԭ��
	�����õݹ�ʵ�֣�
	1.ʮ����������2ȡ��
	2.�õ������ٳ���2����ȡ��
	3.�ٳ���2ȡ��
	4.����
	5.ֱ����Ϊ0��ʱ��������������
	15 ---> 1111
*/

#include <stdio.h>

void DecToBin(int iDec)
{
	int iTmp = 0;
	int iSum = 0;
	if (iDec == 0)
	{
		return;
	}
	else
	{
		iTmp = iDec % 2;
		DecToBin(iDec / 2);
		printf("%d", iTmp);
	}
}

int main()
{
	int iDec = 22;
	DecToBin(iDec);
	printf("\n");
	//printf("%d ---> %d\n", iDec, iBin);
	return 0;
}
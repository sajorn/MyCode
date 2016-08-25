/*
	ʵ��itoa������ת�����ַ����ĺ�������
	ԭ��
	1.ȡ�����ĸ���ֵ
	2.��ÿһ��ֵת�����ַ��󸳸��ַ���������
	3.����ַ�������
	123 ---> ��123��
*/

#include <stdio.h>

void MyItoa(int iNum, char* str);

int main()
{
	int iNum = -21234;
	char cArray[100] = { 0 };
	MyItoa(iNum, cArray);
	printf("%s\n", cArray);
	return 0;
}

void MyItoa(int iNum, char* str)
{
	int i = 0; //���������ж���λ
	int tmpNum = iNum;

	while (tmpNum)
	{
		i++;
		tmpNum /= 10;
	}

	if (iNum > 0)
	{
		while (iNum)
		{
			str[--i] = (iNum % 10) + '0';
			iNum /= 10;
		}
	}
	else
	{
		iNum = -iNum;
		str[0] = '-';		
		int j;
		for (j = i; j > 0; --j)
		{
			str[j] = (iNum % 10) + '0';
			iNum /= 10;
		}
	}
}
/*
	��쳲��������еĵ�n�� a = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144����}
	ԭ��
	�����õݹ�ʵ�֣�
	1.��һ�����͵ڶ������ǹ̶��ģ�ֱ�����
	2.�����������ڵڶ���3-1�������ӵ�һ��3-2������
	3.���ĸ������ڵ�����4-1�������ӵڶ���4-2������
	4.�Դ�����
	10 ---> 34
*/

#include <stdio.h>

int FibArray(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	return FibArray(n - 1) + FibArray(n - 2);
}

int main()
{
	int iNum = 10;
	int iResult = FibArray(iNum);
	printf("%d\n", iResult);
	return 0;
}
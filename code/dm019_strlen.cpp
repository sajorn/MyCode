/*
	һ.�ݹ�ʵ��strlen��������
	ԭ��
	1.�����ַ�����0���Ƚ�ȥ
	2.��Ϊ���ַ�ʱ�����ȼ�1�ڴ���
	��.ָ��ʵ��strlen��������
	ԭ��
	1.ָ��ָ���һ���ַ�
	2.�ж��Ƿ�Ϊ���ַ�
	3.ָ��ƫ�Ƶ���һ���ַ�
*/

#include <stdio.h>

int MyStrlen(char str[], int n)
{
	if (str[n])
	{
		MyStrlen(str, n + 1);
	}
	else
	{
		return n;
	}
	
}

int MyStrlenByPoint(char str[])
{
	int iLen = 0;
	while (*str)
	{
		iLen++;
		str++;
	}
	return iLen;
}

int main()
{
	char strTest[20] = "hello";
	int iLen = MyStrlen(strTest,0);
	int iLen1 = MyStrlenByPoint(strTest);
	printf("MyStrlen: %d\n", iLen);
	printf("MyStrlenByPoint: %d\n", iLen1);

	return 0;
}
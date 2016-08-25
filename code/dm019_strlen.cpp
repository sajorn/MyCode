/*
	一.递归实现strlen函数功能
	原理：
	1.传递字符串和0长度进去
	2.不为空字符时，长度加1在传递
	二.指针实现strlen函数功能
	原理：
	1.指针指向第一个字符
	2.判断是否为空字符
	3.指针偏移到下一个字符
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
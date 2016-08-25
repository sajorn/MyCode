/*
	实现itoa（整数转换成字符）的函数功能
	原理：
	1.取整数的各项值
	2.将每一项值转换成字符后赋给字符串数组中
	3.输出字符串数组
	123 ---> ”123“
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
	int i = 0; //计算整数有多少位
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
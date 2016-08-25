/*
	10进制转换成2进制数
	原理：
	（利用递归实现）
	1.十进制数除以2取余
	2.得到的商再除以2继续取余
	3.再除以2取余
	4.……
	5.直到商为0的时候，逆序把余数输出
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
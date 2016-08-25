/*
	10进制转换成16进制数
	原理：
	（利用递归实现）
	1.10进制数除以16取余
	2.得到的商再继续除以16取余
	3.一直取余直到商的结果小于16或者等于0
	4.逆序输出取余的结果
	5.大于10的数用ABCDEF表示
	255 ---> FF
*/

#include <stdio.h>

void DecToHex(int iDec)
{
	int iTmp = iDec % 16;
	if (iDec != 0)
	{	
		DecToHex(iDec / 16);
		switch (iTmp)
		{
		case 10: printf("A"); break;
		case 11: printf("B"); break;
		case 12: printf("C"); break;
		case 13: printf("D"); break;
		case 14: printf("E"); break;
		case 15: printf("F"); break;
		default: 
			printf("%d", iTmp); 
			break;
		}
	}
	else
	{
		return;
	}
}

int main()
{
	int iDec = 255;
	DecToHex(iDec);
	printf("\n");
	return 0;
}
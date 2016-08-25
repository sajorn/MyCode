/*
输入n个数，n<=100，找到其中最小的数和最大的数

第一行一个整数n
接下来一行n个整数，每个整数不超过2^31 -1
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int iNum, iMax, iMin;
	int a[100];
	scanf("%d", &iNum);

	for (int i = 0; i < iNum; ++i)
	{
		scanf("%d", &a[i]);
	}
	iMax = a[0];
	iMin = a[0];
	for (int i = 1; i < iNum; ++i)
	{
		if (iMax < a[i])
		{
			iMax = a[i];
		}
		if (iMin > a[i])
		{
			iMin = a[i];
		}
	}
	printf("%d %d\n", iMin, iMax);
	return 0;
}
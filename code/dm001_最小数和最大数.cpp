/*
����n������n<=100���ҵ�������С������������

��һ��һ������n
������һ��n��������ÿ������������2^31 -1
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
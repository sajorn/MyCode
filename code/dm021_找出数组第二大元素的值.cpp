/*
	�ҳ�����ڶ���Ԫ��
	˼·:
	1.���һ���͵ڶ���Ԫ�طֱ������mMax�͵ڶ���sMax
	2.������������Ԫ��mMax����������򽫵�ǰmMax�������ڶ���Ԫ��sMax��mMax���������Ǹ�
	3.������С������mMax�����ִ���sMax����������Ǹ�������sMax
	23, 45, 13, 57, 78, 95, 35, 88, 2, 65 ---> 88
*/

#include <stdio.h>

int FindSecNum(int testArr[])
{
	int *mMax = &testArr[0];
	int *sMax = &testArr[1];
	int i;
	for (i = 2; i < 10; ++i)
	{
		if (*mMax < *(testArr + i))
		{
			*sMax = *mMax;
			*mMax = *(testArr + i);
		}
		if (*(testArr + i) > *sMax && *(testArr + i) < *mMax)
		{
			*sMax = *(testArr + i);
		}
	}
	return *sMax;
}

int main()
{
	int tArray[10] = { 23, 45, 13, 57, 78, 95, 35, 88, 2, 65 };
	int secMax = FindSecNum(tArray);
	printf("�ڶ���Ԫ�أ�%d\n", secMax);
	return 0;
}
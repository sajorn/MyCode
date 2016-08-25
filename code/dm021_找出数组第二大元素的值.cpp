/*
	找出数组第二大元素
	思路:
	1.设第一个和第二个元素分别是最大mMax和第二大sMax
	2.当遇到比最大的元素mMax还大的数，则将当前mMax数赋给第二大元素sMax，mMax则等于最大那个
	3.当遇到小于最大的mMax但是又大于sMax的数，则把那个数赋给sMax
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
	printf("第二大元素：%d\n", secMax);
	return 0;
}
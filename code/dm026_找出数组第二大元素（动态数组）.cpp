/*
	动态数组实现找出数组第二大元素
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int main()
{
	int numMax;
	puts("输入数组大小:");
	scanf("%d", &numMax);
	int* arr = (int*)calloc(numMax, sizeof(int));
	
	int index;
	for (index = 0; index < numMax; ++index)
	{
		printf("array[%d] = ", index + 1);
		scanf("%d", &arr[index]);
	}

	int iFirstMax = INT_MIN;
	int iSecondMax = INT_MIN;

	for (index = 0; index < numMax; ++index)
	{
		if (iFirstMax < arr[index])
		{
			iSecondMax = iFirstMax;
			iFirstMax = arr[index];
		}
		if (iSecondMax < arr[index] && iFirstMax > arr[index])
		{
			iSecondMax = arr[index];
		}
	}
	printf("第一大的数：%d\n", iFirstMax);
	printf("第二大的数: %d\n", iSecondMax);

	free(arr);
	return 0;
}
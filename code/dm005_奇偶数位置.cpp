/*
 输入一个整数数组。 实现一个函数，将所有的奇数放在数组的前半部分， 所有的偶数放在数组的后半部分。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 100

void ChangeNum(int* arr, int iLen)
{
	char tempArr[MAX];
	int j = 0;
	for (int i = 0; i < iLen; ++i)
	{
		if (arr[i] % 2 != 0)
		{
			tempArr[j++] = arr[i];
		}
	}
	for (int i = 0; i < iLen; ++i)
	{
		if (arr[i] % 2 == 0)
		{
			tempArr[j++] = arr[i];
		}
	}

	for (int i = 0; i < j; i++)
	{
		printf("%d ", tempArr[i]);
	}
	printf("\n");
}

void ChangeNumPlus(int* arr, int iLen)
{

	for (int i = 0, j = iLen - 1; i < j; ++i, --j)
	{
		if (arr[i] % 2 == 0)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i--;
		}
		if (arr[j] % 2 != 0)
		{
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			j++;
		}
	}
	for (int i = 0; i < iLen; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arrNum[MAX];
	puts("输入一个整型数组: ");
	unsigned int i = 0;
	while (scanf("%d", &arrNum[i]))
	{
		i++;
	}

	//ChangeNum(arrNum, i);
	ChangeNumPlus(arrNum, i);

	return 0;
}
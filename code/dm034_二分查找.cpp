/*
	二分查找：（前提是对已经排好序的数组进行查找)
*/

#include <stdio.h>

void FastSort(int* a, int len)
{
	int i, j;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = i + 1; j < len; ++j)
		{
			if (a[i] > a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

void PrintArr(int* a, int len)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		printf("array[%d] = %d\n", i, a[i]);
	}
}

int BinFind(int* arr, int low, int high, int key)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == arr[mid])
		{
			return mid;
		}
		else if (key > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int myArr[] = { 3, 5, 6, 12, 14, 7, 43, 87, 54, 44 };
	int aLen = sizeof(myArr) / sizeof(int);
	FastSort(myArr, aLen);
	PrintArr(myArr, aLen);
	int result = BinFind(myArr, 0, 9, 6);
	printf("Res = %d\n", result);
	return 0;
}
/*
	选择排序
	基本思路：遍历数组，找出最小/最大的一个数，放到最前面

	例子：
		13	17	10	29	33	21
	1	10	17	13	29	33	21
	2	10	13	17	29	33	21
	3	10	13	17	21	33	29
	4	10	13	17	21	29	33
*/

#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Print(int* arr, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int FindMinNum(int* arr, int low, int high) //在一定的范围内找到数组中的最小值
{
	int min = arr[low];
	int i;
	int mKey = low;
	for (i = low + 1; i < high; ++i)
	{
		if (min > arr[i])
		{
			mKey = i;
		}
	}
	return mKey;
}

void Sort(int* arr, int n)
{
	int i, j;
	int tj = 0;
	
	for (i = 0; i < n - 1; ++i) //循环的次数
	{
		/*
			int min = arr[i];
			for (j = i; j < n; ++j)
			{
				if (min > arr[j])
				{
					min = arr[j];
					tj = j;
				}
			}
			Swap(&arr[i], &arr[tj]);
		*/
		int minKey = FindMinNum(arr, i, n);
		if (i != minKey) //第一个数不是最小的数
		{
			Swap(&arr[i], &arr[minKey]);
		}

		Print(arr, n);
	}
}


int main()
{
	int myArray[] = { 13, 17, 10, 29, 33, 21 };
	int arrLen = sizeof(myArray) / sizeof(int);
	Sort(myArray, arrLen);
	//Print(myArray, arrLen);
	return 0;
}
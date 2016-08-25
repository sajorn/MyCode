/*
 实现的原理:
	3 5 4 2 1 6 7 9
1	  4 5
        2 5
		  1 5
	3 4 2 1 5 6 7 9
2	  2 4
        1 4
	3 2 1 4 5 6 7 9
3	2 3
	  1 3
	2 1 3 4 5 6 7 9
4   1 2
	1 2 3 4 5 6 7 9
*/

#include <stdio.h>

int main()
{
	int arr[8] = { 3, 5, 4, 2, 1, 6, 7, 9 };

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 1; j < 8 - i; ++j)
		{
			if (arr[j-1] > arr[j]) //前后进行比较
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
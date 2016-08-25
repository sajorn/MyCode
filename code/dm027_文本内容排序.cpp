#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#pragma warning(disable:4996)

void ArraySort(int* arr, int len)
{
	int i, j;
	for (i = 0; i < len; ++i)
	{
		for (j = 1; j < len - i; ++j)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	FILE* fp = fopen("sort.txt", "r");
	if (!fp)
	{
		printf("open error\n");
	}

	int count = 1;
	int* arr = (int*)malloc(sizeof(int) * MAX * count);
	int index = 0;
	char buf[128];
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		arr[index] = atoi(buf);
		index++;
		if (index >= (MAX * count))
		{
			count++;
			realloc(arr, sizeof(int) * MAX * count);
		}
	}

	ArraySort(arr, index);

	FILE* fp2 = fopen("sort_after.txt", "w");
	if (!fp2)
	{
		printf("open error\n");
	}

	int i;
	for (i = 0; i < index; ++i)
	{
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "%d\n", arr[i]);
		fputs(buf, fp2);
	}

	fclose(fp);
	fclose(fp2);

	printf("Done!\n");

	free(arr);

	return 0;
}
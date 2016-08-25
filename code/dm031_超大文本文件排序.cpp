#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

#define MAX 1025
//���������ķ����������������±�����������
//�����ֵ��ʾ����������ֵĴ�������󽫸�������±�������ֵĴ���
	
int main()
{
	srand(time(NULL));
	FILE* fp = fopen("lar_sort.txt", "w");
	if (!fp)
	{
		printf("open error!\n"); 
		return 0;
	}
	for (int i = 0; i < 1000000; ++i)
	{
		fprintf(fp, "%d\n", rand() % MAX);
	}
	fclose(fp);

	fp = fopen("lar_sort.txt", "r");
	if (!fp)
	{
		printf("open error!\n");
		return 0;
	}

	FILE* fp2 = fopen("lar_sort_after.txt", "w");
	if (!fp2)
	{
		printf("open error\n");
		return 0;
	}

	int array[MAX] = { 0 };
	while (!feof(fp))
	{
		char buf[127] = { 0 };
		fgets(buf, sizeof(buf), fp);
		if (buf[0] != '\0')
		{
			int value = atoi(buf);
			++array[value];
		}
	}

	int i, j;
	for (i = 0; i < MAX; ++i)
	{
		for (j = 0; j < array[i]; ++j)
		{
			fprintf(fp2, "%d\n", i);
		}
	}

	fclose(fp);
	fclose(fp2);
	printf("Done!\n");
	return 0;
}
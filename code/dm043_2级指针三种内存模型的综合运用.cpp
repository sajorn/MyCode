/*
	int sort(char *p[], int count, char **p, int *ncount);
	int sort(char *p[], int count, char (*p)[30], int *ncount);
	int sort(char (*p)[30], int ncount,  char **p, int *ncount);

	把第一种内存模型第二种内存模型结果copy到第三种内存模型中，并排序，打印
	char ** sort(char **p1, int num1, char (*p)[30], int num2, int *num3 );

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int Sort(char* p1[], int num1, char(*p2)[30], int num2, char*** p3, int* num3)
{
	int len = 0; //第三个字符串长度
	len = num1 + num2;
	*num3 = len;

	char** tmp = NULL;
	tmp = (char**)malloc(sizeof(char*)*len);
	if (!tmp)
	{
		return -1;
	}
	int i;
	int tLen;
	for (i = 0; i < num1; ++i)
	{
		tLen = strlen(p1[i]) + 1;
		tmp[i] = (char*)malloc(sizeof(char) * tLen);
		if (!tmp[i])
		{
			return -1;
		}
		strncpy(tmp[i], p1[i], tLen);
	}

	int j;
	for (j = 0; j < num2; ++i, ++j)
	{
		tLen = strlen(*p2) + 1;
		tmp[i] = (char*)malloc(sizeof(char) * tLen);
		if (!tmp[i])
		{
			return -1;
		}
		
		strncpy(tmp[i], p2[j], tLen);
	}

	char* tp; //用于数据交换的临时指针
	for (i = 0; i < len; ++i)
	{
		for (j = i + 1; j < len; ++j)
		{
			if (strcmp(tmp[i], tmp[j]) > 0)
			{
				tp = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = tp;
			}
		}
	}

	*p3 = tmp;

	return 0;
}

void Print(char** p3, int len)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		printf("%s\n", p3[i]);
	}
}

void Free(char*** p3, int len)
{
	if (!p3)
	{
		return;
	}
	int i;
	char** tmp = NULL;
	tmp = *p3;

	if (!tmp)
	{
		return;
	}
	for (i = 0; i < len; ++i)
	{
		if (!(*tmp))
		{
			return;
		}
		free(*tmp);
		*tmp = NULL;
	}
	free(tmp);
	tmp = NULL;
}

int main()
{
	char *p1[] = { 
		"1111111", 
		"333333", 
		"2222222" 
	};

	char p2[4][30] = {
		"aaaaaa",
		"ccccc",
		"bbbbbb"
	};

	char** p3 = NULL;

	int ret;
	int len1 = sizeof(p1) / sizeof(*p1);
	int len2 = 3;
	int len3 = 0;
	ret = Sort(p1, len1, p2, len2, &p3, &len3);
	if (ret)
	{
		printf("error:%d\n", ret);
		return -1;
	}
	Print(p3, len3);

	Free(&p3, len3);

	return 0;
}
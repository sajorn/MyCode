/*
	通过二级指针分配一块内存空间，然后将这块内存空间分成若干块，每块内存空间
	又分配一块内存空间，进行存储值
*/	
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEM_NUM 5

char** GetMem(char** p)
{
	p = (char**)malloc(sizeof(char*) * MEM_NUM);

	int i;
	for (i = 0; i < MEM_NUM; ++i)
	{
		p[i] = (char*)malloc(sizeof(char) * 20);
		sprintf(p[i], "%d", i + 1);
	}

	return p;
}

//通过3级指针修改2级指针的值
int GetMem1(char*** p)
{
	if (!p)
	{
		return -1;
	}

	char** tmp = NULL;

	tmp = (char**)malloc(sizeof(char*)*MEM_NUM);

	int i;
	for (i = 0; i < MEM_NUM; ++i)
	{
		tmp[i] = (char*)malloc(sizeof(char) * 20);
		sprintf(tmp[i], "%d", i + 1);
	}

	*p = tmp;

	return 0;
}

//通过3级指针释放内存
int FreeMem1(char*** p)
{
	if (!p)
	{
		return -1;
	}

	char** tmp = NULL;
	tmp = *p;

	int i;
	for (i = 0; i < MEM_NUM; ++i)
	{
		if (tmp[i])
		{
			free(tmp[i]);
			tmp[i] = NULL;
			if (tmp[i] == NULL)
			{
				printf("tmp[%d]为空\n", i);
			}
		}
	}
	free(tmp);
	*p = NULL;
	return 0;

}

void PrintArray(char** p)
{
	int i;
	for (i = 0; i < MEM_NUM; ++i)
	{
		printf("%s\n", p[i]);
	}
}

void FreeMem(char** p)
{
	int i;
	for (i = 0; i < MEM_NUM; ++i)
	{
		if (p[i])
		{
			free(p[i]);
			p[i] = NULL;
		}
	}

	if (p)
	{
		free(p);
		p = NULL;
	}
}

void SortArray(char** p)
{
	int i, j;
	char tArr[30] = { 0 };
	for (i = 0; i < MEM_NUM; ++i)
	{
		for (j = i + 1; j < MEM_NUM; ++j)
		{
			if (strcmp(p[i], p[j]) < 0)
			{
				strcpy(tArr, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], tArr);
			}
		}
	}
}

int main()
{
	char** p2 = NULL;
	//p2 = GetMem(p2);
	GetMem1(&p2);
	PrintArray(p2);
	SortArray(p2);
	PrintArray(p2);
	FreeMem1(&p2);
	//FreeMem(p2);
	return 0;
}
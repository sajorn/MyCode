#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��������ָ��
typedef int(MyIntArray)[5]; //�൱�� int a[5];
typedef int(*MyIntArrayPoint)[5]; //�൱�� int (*a)[5];

int main()
{
	MyIntArray *a; //�൱�ڶ�����int (*a)[5];
	MyIntArrayPoint b; //�൱�ڶ�����int (*b)[5];

	MyIntArray tmpa;
	a = &tmpa;
	b = a;
	int i;
	for (i = 0; i < 5; ++i)
	{
		(*a)[i] = i + 1;
	}

	for (i = 0; i < 5; ++i)
	{
		printf("%d ", (*b)[i]);
	}

	printf("\n");

	return 0;
}
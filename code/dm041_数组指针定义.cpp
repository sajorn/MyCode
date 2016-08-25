#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义数组指针
typedef int(MyIntArray)[5]; //相当于 int a[5];
typedef int(*MyIntArrayPoint)[5]; //相当于 int (*a)[5];

int main()
{
	MyIntArray *a; //相当于定义了int (*a)[5];
	MyIntArrayPoint b; //相当于定义了int (*b)[5];

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
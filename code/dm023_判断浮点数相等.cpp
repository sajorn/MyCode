/*
	给出两个浮点数，请你判断这两个浮点数是否相等
	原理：
	通过区间进行比较，两数相减如果位于某个精确范围，则视为0，那么这两数就相等。否则不相等
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	double a, b;
	scanf("%lf%lf", &a, &b);
	double x = abs(a - b);
	printf(x <= 1e-8 ? "yes\n" : "no\n");
	return 0;
}




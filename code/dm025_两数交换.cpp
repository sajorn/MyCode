/*
	实现两数交换，函数内部不能定义任何变量
	原理：
	1.两数相加赋给第一个数
	2.它们的和减去第二个数并赋给第二个数
	3.然后它们的和减去第二个数赋给第一个数
*/

#include <stdio.h>

void SwapByPoint(int* a, int* b) //a=5, b=4
{
	*a += *b; // a=5+4=9
	*b = *a - *b; // b=9-4=5
	*a -= *b; //a=9-5=4
}
void MySwap(void (*p)(int*, int*), int* a, int* b)
{
	return p(a, b);
}

int main()
{
	int a = 5;
	int b = 4;
	MySwap(SwapByPoint, &a, &b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
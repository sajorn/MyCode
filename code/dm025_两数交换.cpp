/*
	ʵ�����������������ڲ����ܶ����κα���
	ԭ��
	1.������Ӹ�����һ����
	2.���ǵĺͼ�ȥ�ڶ������������ڶ�����
	3.Ȼ�����ǵĺͼ�ȥ�ڶ�����������һ����
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
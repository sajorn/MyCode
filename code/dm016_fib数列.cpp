/*
	求斐波那契数列的第n项 a = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144……}
	原理：
	（利用递归实现）
	1.第一个数和第二个数是固定的，直接输出
	2.第三个数等于第二（3-1）个数加第一（3-2）个数
	3.第四个数等于第三（4-1）个数加第二（4-2）个数
	4.以此类推
	10 ---> 34
*/

#include <stdio.h>

int FibArray(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	return FibArray(n - 1) + FibArray(n - 2);
}

int main()
{
	int iNum = 10;
	int iResult = FibArray(iNum);
	printf("%d\n", iResult);
	return 0;
}
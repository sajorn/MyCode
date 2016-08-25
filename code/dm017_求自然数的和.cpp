/*
	求自然数的和
	原理：
	（递归实现）
	第n项 + 第n-1项 + 第n-2项 + ... + 0
	100 ---> 5050
*/

#include <stdio.h>

int AddSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n + AddSum(n - 1);
}

int main()
{
	int iTest = 100;
	printf("%d\n", AddSum(iTest));
	return 0;
}
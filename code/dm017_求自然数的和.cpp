/*
	����Ȼ���ĺ�
	ԭ��
	���ݹ�ʵ�֣�
	��n�� + ��n-1�� + ��n-2�� + ... + 0
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
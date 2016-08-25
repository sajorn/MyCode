#include <stdio.h>
#include <string.h>
/*调整数组中数字的顺序，奇数在前，偶数在后*/

int TransformArray1(int* nArray, int len)
{
	if (nArray == NULL)
	{
		return -1;
	}

	int i = 0, j = 0, k = 0;
	char oddArray[50];
	char evenArray[50];

	while (len > 0)
	{
		if (nArray[i] % 2 == 0)//偶数
		{
			evenArray[j] = nArray[i];
			j++;
		}
		else
		{
			oddArray[k] = nArray[i];
			k++;
		}
		i++;
		len--;
	}
	
	for (i = 0; i < k; ++i)
	{
		nArray[i] = oddArray[i];
	}
	for (i = 0; i < j; ++i, ++k)
	{
		nArray[k] = evenArray[i];
	}

	return 0;
}

int TransformArray2(int* nArray, int len)
{
	if (nArray == NULL)
	{
		return -1;
	}

	int* pOdd = nArray; //奇数指针
	int* pEven = nArray + len - 1; //偶数指针

	while (pOdd < pEven)
	{
		while (pOdd < pEven && (*pOdd) % 2 == 1) //找偶数
		{
			pOdd++;
		}
		while (pOdd < pEven && (*pEven) % 2 == 0) //找奇数
		{
			pEven--;
		}
		if (pOdd < pEven)
		{
			int tmp = *pOdd;
			*pOdd = *pEven;
			*pEven = tmp;
		}
	}

	return 0;
}

int main()
{
	int nNumber[100] = { 0 };
	int maxNum = 0; //记录输入了多少个数字
	int i = 0;
	while (scanf("%d", &nNumber[i]))
	{
		maxNum++;
		i++;
	}
	TransformArray2(nNumber, maxNum);
	i = 0;
	for (; i < maxNum; ++i)
	{
		printf("%d ", nNumber[i]);
	}
	printf("\n"); 
	return 0;
}
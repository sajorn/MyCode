/*
	将字符串数字转换成整数
	原理：
	1.计算字符串长度
	2.将每一位字符读出，通过减去‘0’字符转换成整数
	3.将得到的整数乘以10的长度-1次方
	4.将得到的结果进行相加
	“123456” ---> 123456
*/

#include <stdio.h>

int main()
{
	char cTest[20] = "123456";
	/*计算字符串的长度*/
	int sLen = 0;
	while (cTest[sLen++])
		;
	sLen--;

	/*读出每一位字符并转换成整数并相加*/
	int i;
	int iSum = 0;
	
	for (i = 0; i < sLen; ++i)
	{
		int iTemp = cTest[i] - '0';
		int tmpLen = sLen - i;
		while (--tmpLen)
		{		
			iTemp *= 10;
		}

		iSum += iTemp;
	}

	printf("result = %d\n", iSum);
	return 0;
}

/*
	���ַ�������ת��������
	ԭ��
	1.�����ַ�������
	2.��ÿһλ�ַ�������ͨ����ȥ��0���ַ�ת��������
	3.���õ�����������10�ĳ���-1�η�
	4.���õ��Ľ���������
	��123456�� ---> 123456
*/

#include <stdio.h>

int main()
{
	char cTest[20] = "123456";
	/*�����ַ����ĳ���*/
	int sLen = 0;
	while (cTest[sLen++])
		;
	sLen--;

	/*����ÿһλ�ַ���ת�������������*/
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

/*
	10����ת����16������
	ԭ��
	�����õݹ�ʵ�֣�
	1.10����������16ȡ��
	2.�õ������ټ�������16ȡ��
	3.һֱȡ��ֱ���̵Ľ��С��16���ߵ���0
	4.�������ȡ��Ľ��
	5.����10������ABCDEF��ʾ
	255 ---> FF
*/

#include <stdio.h>

void DecToHex(int iDec)
{
	int iTmp = iDec % 16;
	if (iDec != 0)
	{	
		DecToHex(iDec / 16);
		switch (iTmp)
		{
		case 10: printf("A"); break;
		case 11: printf("B"); break;
		case 12: printf("C"); break;
		case 13: printf("D"); break;
		case 14: printf("E"); break;
		case 15: printf("F"); break;
		default: 
			printf("%d", iTmp); 
			break;
		}
	}
	else
	{
		return;
	}
}

int main()
{
	int iDec = 255;
	DecToHex(iDec);
	printf("\n");
	return 0;
}
/*
 �Ӽ���������һ���ַ����� Ҫ��ֱ�ͳ�Ƴ���д��ĸ�� Сд��ĸ�����֣� �ո��Լ������ַ��ĸ���
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ARMAX 1024

int main()
{
	char cWord[ARMAX] = { 0 };
	unsigned int iBigLetter = 0; //��д��ĸ
	unsigned int iSmallLetter = 0; //Сд��ĸ
	unsigned int iNumber = 0; //����
	unsigned int iSpace = 0; //�ո�
	unsigned int iOther = 0; //����

	printf("����һ���ַ���: \n");
	gets(cWord);

	for (int i = 0; cWord[i] != '\0'; ++i)
	{
		if (isupper(cWord[i]))	iBigLetter++;
		else if (islower(cWord[i]))	iSmallLetter++;
		else if (isdigit(cWord[i])) iNumber++;
		else if (isspace(cWord[i])) iSpace++;
		else iOther++;
	}

	printf("ͳ������: \n");
	printf("��д��ĸ��%d��\n", iBigLetter);
	printf("Сд��ĸ��%d��\n", iSmallLetter);
	printf("������%d��\n", iNumber);
	printf("�ո���%d��\n", iSpace);
	printf("�����ַ���%d��\n", iOther);

	return 0;
}
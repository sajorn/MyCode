#include <stdio.h>
/*
 * ͳ���ַ����пո�������д��ĸ��Сд��ĸ�����ֺ������ַ��ĸ���
 */
int CountString(char* buf, int* nSpace, int* nBig, int* nSmall, int* nNum, int* nOther)
{
	if (buf == NULL)
	{
		return -1;
	}
	int i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == ' ')
		{
			(*nSpace)++;
		}
		else if (buf[i] >= 'A' && buf[i] <= 'Z')
		{
			(*nBig)++;
		}
		else if (buf[i] >= 'a' && buf[i] <= 'z')
		{
			(*nSmall)++;
		}
		else if (buf[i] >= '0' && buf[i] <= '9')
		{
			(*nNum)++;
		}
		else
		{
			(*nOther)++;
		}
		i++;
	}

	return 0;
}

int main()
{
	int nSpaceCount; //�ո���
	int nBigCount; //��д��ĸ
	int nSmallCount; //Сд��ĸ
	int nNumCount; //����
	int nOtherCount; //�����ַ�

	char buf[1000];
	while (gets(buf))
	{
		nSpaceCount = 0;
		nBigCount = 0;
		nSmallCount = 0;
		nNumCount = 0;
		nOtherCount = 0;
		CountString(buf, &nSpaceCount, &nBigCount, &nSmallCount, &nNumCount, &nOtherCount); //ͳ���ַ����еĸ���
		printf("Space: %d, BigLetter: %d, SmallLetter: %d, Number: %d, Other: %d\n",
			nSpaceCount, nBigCount, nSmallCount, nNumCount, nOtherCount);
	}

	return 0;
}
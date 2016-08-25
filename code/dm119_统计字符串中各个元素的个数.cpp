#include <stdio.h>
/*
 * 统计字符串中空格数，大写字母，小写字母，数字和其他字符的个数
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
	int nSpaceCount; //空格数
	int nBigCount; //大写字母
	int nSmallCount; //小写字母
	int nNumCount; //数字
	int nOtherCount; //其他字符

	char buf[1000];
	while (gets(buf))
	{
		nSpaceCount = 0;
		nBigCount = 0;
		nSmallCount = 0;
		nNumCount = 0;
		nOtherCount = 0;
		CountString(buf, &nSpaceCount, &nBigCount, &nSmallCount, &nNumCount, &nOtherCount); //统计字符串中的个数
		printf("Space: %d, BigLetter: %d, SmallLetter: %d, Number: %d, Other: %d\n",
			nSpaceCount, nBigCount, nSmallCount, nNumCount, nOtherCount);
	}

	return 0;
}
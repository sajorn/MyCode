/*
	解析文本内容，计算文本内的表达式并输出结果
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int CalcMyStr(const char* s) //解析字符串
{
	char num1[128] = { 0 };
	char oper = 0;
	char num2[128] = { 0 };

	int sLen = strlen(s);
	int i;
	for (i = 0; i < sLen; ++i)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			strncpy(num1, s, i);
			oper = s[i];
			break;
		}
	}

	int j = i + 1;
	for (; i < sLen; ++i)
	{
		if (s[i] == '=')
		{
			strncpy(num2, &s[j], i - j);
			break;
		}
	}

	int iNum1 = atoi(num1);
	int iNum2 = atoi(num2);

	switch (oper)
	{
	case '+':
		return iNum1 + iNum2;
	case '-':
		return iNum1 - iNum2;
	case '*':
		return iNum1 * iNum2;
	case '/':
	{
		if (iNum2)
		{
			return iNum1 / iNum2;
		}
		else
		{
			break;
		}
	}
	default:
		break;
	}
	return 0;
}

void CutEnter(char* buf)
{
	int sLen = strlen(buf);
	if (buf[sLen - 1] == '\n')
	{
		buf[sLen - 1] = 0;
	}
}

int main()
{
	FILE *fp = fopen("calc.txt", "r");
	if (!fp)
	{
		printf("open error\n");
		return 0;
	}

	FILE *fp2 = fopen("calc_after.txt", "w");
	if (!fp2)
	{
		printf("open error\n");
		return 0;
	}

	char buf[128]; //记录一行表达式
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		int value = CalcMyStr(buf);
		CutEnter(buf);
		fprintf(fp2, "%s%d\n", buf, value);
	}

	fclose(fp);
	fclose(fp2);

	printf("Done!\n");
	return 0;
}
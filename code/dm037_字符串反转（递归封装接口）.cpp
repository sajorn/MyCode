/*
	递归实现字符串反转
*/

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void Inserve(char* str, char* nStr)
{
	if (!str || !nStr)
	{
		return;
	}

	if (*str == '\0')
	{
		return;
	}

	char* tmp = str;

	Inserve(tmp + 1, nStr);

	strncat(nStr, tmp, 1);
}

int main()
{
	char* buf = "abcdefg";
	char nBuf[256] = { 0 };

	Inserve(buf, nBuf);

	printf("nBuf: %s\n", nBuf);

	return 0;
}
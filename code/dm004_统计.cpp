/*
 从键盘中输入一个字符串， 要求分别统计出大写字母， 小写字母，数字， 空格以及其他字符的个数
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ARMAX 1024

int main()
{
	char cWord[ARMAX] = { 0 };
	unsigned int iBigLetter = 0; //大写字母
	unsigned int iSmallLetter = 0; //小写字母
	unsigned int iNumber = 0; //数字
	unsigned int iSpace = 0; //空格
	unsigned int iOther = 0; //其他

	printf("输入一个字符串: \n");
	gets(cWord);

	for (int i = 0; cWord[i] != '\0'; ++i)
	{
		if (isupper(cWord[i]))	iBigLetter++;
		else if (islower(cWord[i]))	iSmallLetter++;
		else if (isdigit(cWord[i])) iNumber++;
		else if (isspace(cWord[i])) iSpace++;
		else iOther++;
	}

	printf("统计如下: \n");
	printf("大写字母有%d个\n", iBigLetter);
	printf("小写字母有%d个\n", iSmallLetter);
	printf("数字有%d个\n", iNumber);
	printf("空格有%d个\n", iSpace);
	printf("其他字符有%d个\n", iOther);

	return 0;
}
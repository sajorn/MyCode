/*
	实现strncat的功能
	原理：
	1.计算s1的长度
	2.将s2的第一个字符赋给s1的后面
	原理2：
	1.通过指针指向第一个字符串
	2.指针偏移找到第一个字符串的空字符
	3.将第二个字符串接到第一个字符串结尾
	"abcde" + "12345" ----> "abcde12345"
*/
#include <stdio.h>

void MyStrncat(char s1[], char s2[], int iLen);
void MyStrncatByPoint(char s1[], char s2[], int iLen);

int main()
{
	char s1[20] = "abcde";
	char s2[20] = "12345";
	MyStrncat(s1, s2, 3);
	printf("MyStrncat: %s\n", s1);
	MyStrncatByPoint(s1, s2, 3);
	printf("MyStrncatByPoint: %s\n", s1);
	return 0;
}

void MyStrncat(char s1[], char s2[], int iLen)
{
	int len1 = 0;
	while (s1[len1++])
		;
	len1--;

	int i;
	for (i = 0; i < iLen; ++i)
	{
		s1[len1 + i] = s2[i];
	}
}

void MyStrncatByPoint(char s1[], char s2[], int iLen)
{
	char *p1 = s1;
	char *p2 = s2;
	while (*p1)
	{
		p1++;
	}
	p1++;

	int i;
	for (i = 0; i < iLen; ++i)
	{
		*p1++ = *p2++;
		//先执行*p1, *p2, 然后p1++, p2++
	}

}
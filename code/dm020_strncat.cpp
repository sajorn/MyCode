/*
	ʵ��strncat�Ĺ���
	ԭ��
	1.����s1�ĳ���
	2.��s2�ĵ�һ���ַ�����s1�ĺ���
	ԭ��2��
	1.ͨ��ָ��ָ���һ���ַ���
	2.ָ��ƫ���ҵ���һ���ַ����Ŀ��ַ�
	3.���ڶ����ַ����ӵ���һ���ַ�����β
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
		//��ִ��*p1, *p2, Ȼ��p1++, p2++
	}

}
/*
	IP��ַ���ַ���ת����������4������ת����һ��IP��ַ
	IP -> ������
	sscanf()��ȡ��ÿһ���ֵ����������������Ȼ�����
	���� -> IP��
	ָ��ÿ����һ��������ƫ��һ�Σ�������һ��������Ȼ���ٽ���д���ַ�����
*/

#include <stdio.h>
#pragma warning (disable:4996)

void IpToStr(int ip)
{
	unsigned char* p = &ip;
	printf("%u.%u.%u.%u\n", *p, *(p + 1), *(p + 2), *(p + 3));
}

void StrToIp(char str[])
{
	unsigned char a = 0;
	unsigned char b = 0;
	unsigned char c = 0;
	unsigned char d = 0;
	sscanf(str, "%d.%d.%d.%d", &a, &b, &c, &d);
	printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
}

int main()
{
	char str[20] = "192.168.101.33";
	StrToIp(str);

	int ip = 0;
	unsigned char* p = &ip;
	*p = 192;
	p++;
	*p = 168;
	p++;
	*p = 101;
	p++;
	*p = 34;

	IpToStr(ip);

	return 0;
}
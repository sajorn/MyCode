/*
	���������������������ж��������������Ƿ����
	ԭ��
	ͨ��������бȽϣ�����������λ��ĳ����ȷ��Χ������Ϊ0����ô����������ȡ��������
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	double a, b;
	scanf("%lf%lf", &a, &b);
	double x = abs(a - b);
	printf(x <= 1e-8 ? "yes\n" : "no\n");
	return 0;
}




/*
	ͳ�ƻ�ϵ�ASCII�ͺ��ֵĸ���
	ԭ��
	���ֵĵ�һ���ֽڱض��Ǹ���

	"���abc" ---> 5��
*/
#include <stdio.h>

int main()
{
	char cTest[128] = "���abcd�Ұ���";
	int i = 0; //�����ַ���
	int len = 0; //���㳤��

	while (cTest[i])
	{
		if (cTest[i] < 0) //��ʾ�������Ǻ��֣�����Ҫ���������ֽ�
		{
			i++;
		}
		i++;
		len++;
	}

	printf("%d\n", len);
	return 0;
}
/*
	ȥ��һ���ַ����ұ߶���Ŀո�
	ԭ��
	���ַ������濪ʼ�����������ǿո�ʱ����������һλ��Ϊ0 
	"hello world      " ---> "hello world"
*/

#include <stdio.h>

int main()
{
	char cTest[128] = "hello world       ";
	
	int len = 0; // �����ַ�������;
	while (cTest[len++])
		;
	len--;
	int i;
	for (i = len - 1; i >= 0; --i)
	{
		if (cTest[i] != ' ')
		{
			cTest[i + 1] = '\0';
			break;
		}
	}

	printf("(%s)\n", cTest);
	return 0;
}
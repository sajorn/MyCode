/*
	ȥ���ַ�����߶���Ŀո�
	ԭ��
	����1�����ַ�������߿�ʼ��ָ������������ǿո�ʼ���
	����2�������ж��ٸ��ո�Ȼ�󽫺�����ַ���ǰ��
	"     hello world" ---> "hello world"
*/

#include <stdio.h>

int main1()
{
	/*����1*/
	char cTest[128] = "        hello world";
	char *pc = cTest;
	while (*pc == ' ')
	{
		pc++;
	}
	printf("%s\n", pc);
	return 0;
}

int main()
{
	/*����2*/
	char cTest[128] = "        hello world";
	int spaceNum = 0; //�����ж��ٸ��ո�
	while (cTest[spaceNum] == ' ')
	{
		spaceNum++;
	}
	int i = spaceNum; //�Ѻ�����ַ���ǰ��
	while (cTest[i])
	{
		cTest[i - spaceNum] = cTest[i];
		i++;
	}
	cTest[i - spaceNum] = '\0';
	printf("%s\n", cTest);
	return 0;
}
/*
	去掉字符串左边多余的空格
	原理：
	方法1：从字符串的左边开始用指针遍历，遇到非空格开始输出
	方法2：计算有多少个空格，然后将后面的字符往前移
	"     hello world" ---> "hello world"
*/

#include <stdio.h>

int main1()
{
	/*方法1*/
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
	/*方法2*/
	char cTest[128] = "        hello world";
	int spaceNum = 0; //计算有多少个空格
	while (cTest[spaceNum] == ' ')
	{
		spaceNum++;
	}
	int i = spaceNum; //把后面的字符往前移
	while (cTest[i])
	{
		cTest[i - spaceNum] = cTest[i];
		i++;
	}
	cTest[i - spaceNum] = '\0';
	printf("%s\n", cTest);
	return 0;
}
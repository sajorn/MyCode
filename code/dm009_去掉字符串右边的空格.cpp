/*
	去掉一个字符串右边多余的空格
	原理：
	从字符串后面开始遍历，遇到非空格时，将它的下一位赋为0 
	"hello world      " ---> "hello world"
*/

#include <stdio.h>

int main()
{
	char cTest[128] = "hello world       ";
	
	int len = 0; // 计算字符串长度;
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
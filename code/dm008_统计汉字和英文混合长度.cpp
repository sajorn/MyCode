/*
	统计混合的ASCII和汉字的个数
	原理：
	汉字的第一个字节必定是负数

	"你好abc" ---> 5个
*/
#include <stdio.h>

int main()
{
	char cTest[128] = "你好abcd我爱你";
	int i = 0; //遍历字符串
	int len = 0; //计算长度

	while (cTest[i])
	{
		if (cTest[i] < 0) //表示遇到的是汉字，则需要跳过两个字节
		{
			i++;
		}
		i++;
		len++;
	}

	printf("%d\n", len);
	return 0;
}
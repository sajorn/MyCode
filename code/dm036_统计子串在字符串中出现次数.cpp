/*
	统计子串在字符串出现的次数 
	利用strstr函数获取子串的位置
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetNumFromStr(char* p, const char* buf, int* num)
{
	int ret = 0;
	int* count = num;
	if (!p || !buf || !num)
	{
		ret = -1;
		return ret;
	}

	char* tmp = p;
	while (tmp = strstr(tmp, buf))
	{
		++(*count);
		tmp += strlen(buf);
	}

	return ret;
}

int main()
{
	char* words = "asdaabcdabcdabcd123123abvcabcdssabcd";
	char buf[] = "abcd";
	int count = 0;
	//char* pw = words;
	/*do
	{
		pw = strstr(pw, "abcd");
		if (pw)
		{
			++count;
			pw += strlen("abcd");
		}
	} while (pw);*/
	

	/*while (pw = strstr(pw, "abcd"))
	{
		++count;
		pw += strlen("abcd");
		
	}*/

	GetNumFromStr(words, buf, &count);

	printf("出现的次数: %d\n", count);
	return 0;
}
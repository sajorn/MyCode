/*
	1. 有一个字符串符合以下特征(“abcd11111abcd2222abcdqqqqq”)
	要求写一个函数接口，输出以下结果
	1) 求字符串子串(“abcd”)出现的次数，并把结果传出
	2) 把字符串替换成(dcba11111dcba2222dcbaqqqqq)，并把结果传出

	2. 有一个字符串符合以下特征("abcdef,acccd,eeee,aaaa,e3eeeee,sssss,")
	要求写一个函数接口，输出以下结果
	1) 以逗号分割字符串，形成二维数组，并把结果传出
	2) 把二维数组行数运算结果也传出，通过第三种内存模型传出

*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//求字符串子串(“abcd”)出现的次数，并把结果传出
int CalcKeyInBuf(char* p, char* k, int* c)
{
	if (!p || !k)
	{
		return -1;
	}

	char* tp = p;
	int count = 0;

	while (tp)
	{
		tp = strstr(tp, k);
		if (tp)
		{
			count++;
			tp += strlen(k);
		}		
	}
	*c = count;

	return 0;
}

//把字符串替换成(dcba11111dcba2222dcbaqqqqq)，并把结果传出
int ReplaceBuf(char** Source, char* key, char* Target, char** newbuf)
{
	if (!Source || !key || !Target)
	{
		return -1;
	}

	char* tmp = (char*)malloc(sizeof(char) * 50);


	strcpy(tmp, *Source);

	char* t = tmp;
	while (tmp)
	{
		tmp = strstr(tmp, key);
		if (tmp)
		{
			strncpy(tmp, Target, strlen(Target));
			tmp += strlen(Target);
		}
	}
	tmp = t;

	*newbuf = tmp;
	return 0;
}

int main01()
{
	char* buf = "abcd11111abcd2222abcdqqqqq";
	char* key = "abcd";
	int count = 0;
	char* tar = "dcba";
	char* nBuf = NULL;

	CalcKeyInBuf(buf, key, &count);

	ReplaceBuf(&buf, key, tar, &nBuf);

	printf("count = %d\n", count);
	printf("nBuf = %s\n", nBuf);

	if (nBuf)
	{
		free(nBuf);
		nBuf = NULL;
	}

	return 0;
}

//获取该二维数组的行数
int GetArrayLine(char* Source, char seq, int* line)
{
	if (!Source)
	{
		return -1;
	}

	char* tmp = Source;
	int tLine = 0;
	
	do
	{
		tmp = strchr(tmp, seq);
		if (tmp)
		{
			tLine++;
			tmp++;
		}
		else
		{
			break;
		}
	} while (*tmp);

	*line = tLine;
	return 0;
}

//根据字符串返回一个二维数组
int GetArray(char* Source, char seq, char*** Dest)
{
	int ret = 0;
	if (!Source)
	{
		ret = -1;
		return ret;
	}

	int line = 0;
	GetArrayLine(Source, seq, &line);

	char** tmp = (char**)malloc(sizeof(char*) * line);

	if (!tmp)//不够内存分配
	{
		ret = -1;
		return ret;
	}

	char* p1 = Source;
	char* p2 = NULL;
	int strLen = 0;
	int index = 0;

	do
	{
		p2 = strchr(p1, seq); //p2指向分隔符的内存地址
		strLen = p2 - p1; //获取一个字符串的长度
		tmp[index] = (char*)malloc(sizeof(char)*strLen + 1); //动态分配内存空间
		strncpy(tmp[index], p1, strLen); 
		tmp[index][strLen] = '\0'; //将最后一位置为空字符
		index++; //记录下一个一维数组
		p1 = p2 + 1; //p1指针指向分隔符下一个字符串的首字母地址
	} while (*p1);

	*Dest = tmp;

	return ret;
}

int main()
{
	char* buf = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char seq = ',';
	char** tBuf = NULL;
	int line = 0;
	GetArrayLine(buf, seq, &line);
	GetArray(buf, seq, &tBuf);

	int i;
	for (i = 0; i < line; ++i)
	{
		printf("%s\n", tBuf[i]);
	}
	printf("line = %d\n", line);

	for (i = 0; i < line; ++i)
	{
		if (tBuf[i])
		{
			free(tBuf[i]);
			tBuf[i] = NULL;
		}
	}
	free(tBuf);
	tBuf = NULL;

	return 0;
}
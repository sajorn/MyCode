/*
	1. 自定义接口函数实现去除字符串的空格
	int TrimSpace(char* inBuf, char** outBuf);
	"  adsa   " -> "adsa"

	2. 有一个字符串”1a2b3d4z”
	要求写一个函数实现如下功能：
	功能1，把偶数位字符挑选出来，组成一个字符串1,
	功能2，把奇数位字符挑选出来，组成一个字符串2
	功能3，把字符串1和字符串2，通过函数参数传给main并打印
	int GetStr1Str2(char* souce, char* buf1, char* buf2);

	3. 键值对("key = value")字符串， 在开发中经常使用
	要求1， 定义一个接口，实现根据key获取value
	要求2， 键值对中间可能有n多空格，需要去除空格
	键值对字符串格式可能如下
	"key1 = value1"
	"key2 =        value2      "
	"key3   = value3"
	"key4   =   "
	"key5   ="
	int GetKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen);

	int main()
	{
		GetKeyByValue("key1 = value1", "key1", buf, &len);
	}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

//1
int TrimSpace(char* inBuf, char* outBuf)
{
 	int ret = 0;
	char* iTmp = inBuf;
	char* oTmp = outBuf;
	
	if (!iTmp || !outBuf)
	{
		ret = -1;
		printf("字符串为空\n");
		return ret;
	}

	while (*iTmp)
	{
		if (*iTmp == ' ')
		{
			iTmp++;
			continue;
		}
		else
		{
			*oTmp++ = *iTmp++;
		}
	}
	*oTmp = '\0';

	return ret;
}

//两头堵模型
int TrimSpace1(char* inBuf, char* outBuf)
{
	int ret = 0;
	char* p = inBuf;

	if (!inBuf || !outBuf)
	{
		ret = -1;
		printf("错误\n");
		return ret;
	}

	int i = 0;
	int j = strlen(p) - 1;

	while (p[i] == ' ' && p[i] != '\0')
	{
		i++;
	}
	while (p[j] == ' ' && p[j] != '\0')
	{
		j--;
	}

	int strLen = j - i + 1;

	strncpy(outBuf, p + i, strLen);

	outBuf[strLen] = '\0';

	return ret;
}

//函数参数既作输入又作输出
int TrimSpace2(char* buf)
{
	int ret = 0;
	char* p = (char*)malloc(strlen(buf));
	strncpy(p, buf, strlen(buf));

	if (!buf)
	{
		ret = -1;
		printf("错误\n");
		return ret;
	}

	int i = 0;
	int j = strlen(p) - 1;

	while (p[i] == ' ' && p[i] != '\0')
	{
		i++;
	}
	while (p[j] == ' ' && p[j] != '\0')
	{
		j--;
	}

	int strLen = j - i + 1;

	memset(buf, 0, strlen(buf));

	strncpy(buf, p + i, strLen);

	if (p)
	{
		free(p);
		p = NULL;
	}
	return ret;
}

int main01()
{
	char* iBuf = "   avcdas  ";
	char aBuf[20] = "   avcdas1  ";
	char* oBuf = (char*)calloc(20, sizeof(char));

	TrimSpace1(iBuf, oBuf);
	TrimSpace2(aBuf);

	printf("oBuf: (%s)\n", oBuf);
	printf("aBuf: (%s)\n", aBuf);

	if (oBuf)
	{
		free(oBuf);
		oBuf = NULL;
	}

	return 0;
}

//2
int GetStr1Str2(char* souce, char* buf1, char* buf2)
{
	int ret = 0;

	char* tSouce = souce;
	char* tBuf1 = buf1;
	char* tBuf2 = buf2;

	if (!souce || !buf1 || !buf2)
	{
		ret = -1;
		printf("字符串不能为空\n");
		return ret;
	}

	while (*tSouce)
	{
		if (*tSouce >= '0' && *tSouce <= '9')
		{
			if (*tSouce == '0' || *tSouce == '2' || *tSouce == '4'
				|| *tSouce == '6' || *tSouce == '8')
			{
				*tBuf2++ = *tSouce++;
			}
			else
			{
				*tBuf1++ = *tSouce++;
			}
		}
		tSouce++;
	}

	*tBuf1 = '\0';
	*tBuf2 = '\0';

	return ret;
}

int main02()
{
	char* buf = "1a2b3d4z";
	char* jBuf = (char*)malloc(strlen(buf));
	char* oBuf = (char*)malloc(strlen(buf));

	GetStr1Str2(buf, jBuf, oBuf);

	printf("jBuf = %s, oBuf = %s\n", jBuf, oBuf);

	if (jBuf)
	{
		free(jBuf);
		jBuf = NULL;
	}

	if (oBuf)
	{
		free(oBuf);
		oBuf = NULL;
	}

	return 0;
}

//3
int GetKeyByValue(char* keyvaluebuf/*in*/, char* keybuf/*in*/, char* valuebuf/*out*/, int* valuebuflen/*out*/)
{
	int ret = 0;
	if (!keyvaluebuf || !keybuf || !valuebuf)
	{
		ret = -1;
		printf("字符串不能为空\n");
		return ret;
	}

	char* tKeyValueBuf = keyvaluebuf;
	char* tKeyBuf = keybuf;

	tKeyValueBuf = strstr(tKeyValueBuf, tKeyBuf);
	if (!tKeyValueBuf)
	{
		ret = -1;
		printf("找不到该关键字\n");
		return ret;
	}

	tKeyValueBuf += strlen(tKeyBuf);

	tKeyValueBuf = strstr(tKeyValueBuf, "=");
	if (!tKeyValueBuf)
	{
		ret = -1;
		printf("找不到等号\n");
		return ret;
	}

	tKeyValueBuf++;
	TrimSpace1(tKeyValueBuf, valuebuf);

	*valuebuflen = strlen(valuebuf);

	/*while (*tKeyValueBuf)
	{
		if (*tKeyValueBuf == ' ')
		{
			tKeyValueBuf++;
			continue;
		}
		if (*tKeyValueBuf == '=')
		{
			tKeyValueBuf++;
			while (*tKeyValueBuf)
			{
				while (*tKeyValueBuf == ' ')
				{
					tKeyValueBuf++;
					continue;
				}
				*tValueBuf++ = *tKeyValueBuf++;
				tValueBufLen++;
			}
			break;
		}
	}

	*tValueBuf = '\0';

	*valuebuflen = tValueBufLen;*/

	return ret;
}

int main()
{
	char* strBuf = "MySQL_name  =     root       ";
	char* keyBuf = "MySQL_name";
	char* valBuf = (char*)malloc(strlen(strBuf));
	int valLen = 0;

	memset(valBuf, 0, sizeof(valBuf));

	GetKeyByValue(strBuf, keyBuf, valBuf, &valLen);

	printf("valueBuf = %s, valueLen = %d\n", valBuf, valLen);

	if (valBuf)
	{
		free(valBuf);
		valBuf = NULL;
	}

	return 0;
}
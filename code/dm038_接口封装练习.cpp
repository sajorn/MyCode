/*
	1. �Զ���ӿں���ʵ��ȥ���ַ����Ŀո�
	int TrimSpace(char* inBuf, char** outBuf);
	"  adsa   " -> "adsa"

	2. ��һ���ַ�����1a2b3d4z��
	Ҫ��дһ������ʵ�����¹��ܣ�
	����1����ż��λ�ַ���ѡ���������һ���ַ���1,
	����2��������λ�ַ���ѡ���������һ���ַ���2
	����3�����ַ���1���ַ���2��ͨ��������������main����ӡ
	int GetStr1Str2(char* souce, char* buf1, char* buf2);

	3. ��ֵ��("key = value")�ַ����� �ڿ����о���ʹ��
	Ҫ��1�� ����һ���ӿڣ�ʵ�ָ���key��ȡvalue
	Ҫ��2�� ��ֵ���м������n��ո���Ҫȥ���ո�
	��ֵ���ַ�����ʽ��������
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
		printf("�ַ���Ϊ��\n");
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

//��ͷ��ģ��
int TrimSpace1(char* inBuf, char* outBuf)
{
	int ret = 0;
	char* p = inBuf;

	if (!inBuf || !outBuf)
	{
		ret = -1;
		printf("����\n");
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

//�����������������������
int TrimSpace2(char* buf)
{
	int ret = 0;
	char* p = (char*)malloc(strlen(buf));
	strncpy(p, buf, strlen(buf));

	if (!buf)
	{
		ret = -1;
		printf("����\n");
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
		printf("�ַ�������Ϊ��\n");
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
		printf("�ַ�������Ϊ��\n");
		return ret;
	}

	char* tKeyValueBuf = keyvaluebuf;
	char* tKeyBuf = keybuf;

	tKeyValueBuf = strstr(tKeyValueBuf, tKeyBuf);
	if (!tKeyValueBuf)
	{
		ret = -1;
		printf("�Ҳ����ùؼ���\n");
		return ret;
	}

	tKeyValueBuf += strlen(tKeyBuf);

	tKeyValueBuf = strstr(tKeyValueBuf, "=");
	if (!tKeyValueBuf)
	{
		ret = -1;
		printf("�Ҳ����Ⱥ�\n");
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
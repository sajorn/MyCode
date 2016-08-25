/*
	1. ��һ���ַ���������������(��abcd11111abcd2222abcdqqqqq��)
	Ҫ��дһ�������ӿڣ�������½��
	1) ���ַ����Ӵ�(��abcd��)���ֵĴ��������ѽ������
	2) ���ַ����滻��(dcba11111dcba2222dcbaqqqqq)�����ѽ������

	2. ��һ���ַ���������������("abcdef,acccd,eeee,aaaa,e3eeeee,sssss,")
	Ҫ��дһ�������ӿڣ�������½��
	1) �Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
	2) �Ѷ�ά��������������Ҳ������ͨ���������ڴ�ģ�ʹ���

*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//���ַ����Ӵ�(��abcd��)���ֵĴ��������ѽ������
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

//���ַ����滻��(dcba11111dcba2222dcbaqqqqq)�����ѽ������
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

//��ȡ�ö�ά���������
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

//�����ַ�������һ����ά����
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

	if (!tmp)//�����ڴ����
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
		p2 = strchr(p1, seq); //p2ָ��ָ������ڴ��ַ
		strLen = p2 - p1; //��ȡһ���ַ����ĳ���
		tmp[index] = (char*)malloc(sizeof(char)*strLen + 1); //��̬�����ڴ�ռ�
		strncpy(tmp[index], p1, strLen); 
		tmp[index][strLen] = '\0'; //�����һλ��Ϊ���ַ�
		index++; //��¼��һ��һά����
		p1 = p2 + 1; //p1ָ��ָ��ָ�����һ���ַ���������ĸ��ַ
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
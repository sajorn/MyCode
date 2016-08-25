/*
	�ð����Ƕ���һ����ʦ�ṹ�壬ÿ����ʦ����3��ѧ����Ȼ������ʦ��������������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

typedef struct Teacher{
	char* name_;
	char** stdname_; //�����ѧ������
	int age_;
}TEACHER;

int CreateTeacher(TEACHER** myt, int n)
{
	int i, j;

	TEACHER* t = NULL;
	t = (TEACHER*)malloc(sizeof(TEACHER) * n);
	if (!t)
	{
		return -1;
	}

	for (i = 0; i < n; ++i) //��ÿһλ��ʦ�����ڴ�洢��Ϣ
	{
		t[i].name_ = (char*)malloc(sizeof(char) * 50);
		t[i].stdname_ = (char**)malloc(sizeof(char*) * 3);
		t[i].age_ = 0;
		for (j = 0; j < 3; ++j)
		{
			char** tmp = t[i].stdname_;
			tmp[j] = (char*)malloc(sizeof(char) * 50);
			if (!tmp[j])
			{
				return -1;
			}
		}
	}

	*myt = t;

	printf("����ɹ�\n");
	return 0;
}

void PrintMessage(TEACHER* t, int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		printf("����: %s\n", t[i].name_);
		printf("����: %d\n", t[i].age_);
		for (j = 0; j < 3; ++j)
		{
			printf("ѧ��%d: %s\n", j + 1, t[i].stdname_[j]);
		}
	}
}

int FreeTeacher(TEACHER** myt, int n)
{
	if (myt == NULL)
	{
		return -1;
	}

	TEACHER* tmp = *myt;
	for (int i = 0; i < n; ++i)
	{
		if (tmp[i].name_)
		{
			free(tmp[i].name_);
			tmp[i].name_ = NULL;
		}
		for (int j = 0; j < 3; ++j)
		{
			if (tmp[i].stdname_[j])
			{
				free(tmp[i].stdname_[j]);
				tmp[i].stdname_[j] = NULL;
			}
		}		
	}
	free(tmp); //�ͷŸö���ָ��ָ����ڴ��ַ
	tmp = NULL;

	myt = NULL; //����Ұָ��

	return 0;
}

int main()
{
	TEACHER* MyTeacher = NULL;
	CreateTeacher(&MyTeacher, 2);
	int i, j;
	for (i = 0; i < 2; ++i)
	{
		printf("�������%dλ��ʦ��Ϣ:\n", i + 1);
		printf("����:");
		scanf("%s", MyTeacher[i].name_);
		printf("����:");
		scanf("%d", &MyTeacher[i].age_);
		for (j = 0; j < 3; ++j)
		{
			printf("�������%dλ��ʦ���ĵ�%dλѧ������Ϣ:\n", i + 1, j + 1);
			printf("ѧ��������");
			scanf("%s", MyTeacher[i].stdname_[j]);
		}
	}

	PrintMessage(MyTeacher, 2);

	FreeTeacher(&MyTeacher, 2);

	return 0;
}
/*
	该案例是定义一个老师结构体，每个老师带领3个学生，然后按照老师的姓名进行排序
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

typedef struct Teacher{
	char* name_;
	char** stdname_; //带领的学生名字
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

	for (i = 0; i < n; ++i) //给每一位老师分配内存存储信息
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

	printf("分配成功\n");
	return 0;
}

void PrintMessage(TEACHER* t, int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		printf("姓名: %s\n", t[i].name_);
		printf("年龄: %d\n", t[i].age_);
		for (j = 0; j < 3; ++j)
		{
			printf("学生%d: %s\n", j + 1, t[i].stdname_[j]);
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
	free(tmp); //释放该二级指针指向的内存地址
	tmp = NULL;

	myt = NULL; //避免野指针

	return 0;
}

int main()
{
	TEACHER* MyTeacher = NULL;
	CreateTeacher(&MyTeacher, 2);
	int i, j;
	for (i = 0; i < 2; ++i)
	{
		printf("请输入第%d位老师信息:\n", i + 1);
		printf("姓名:");
		scanf("%s", MyTeacher[i].name_);
		printf("年龄:");
		scanf("%d", &MyTeacher[i].age_);
		for (j = 0; j < 3; ++j)
		{
			printf("请输入第%d位老师带的第%d位学生的信息:\n", i + 1, j + 1);
			printf("学生姓名：");
			scanf("%s", MyTeacher[i].stdname_[j]);
		}
	}

	PrintMessage(MyTeacher, 2);

	FreeTeacher(&MyTeacher, 2);

	return 0;
}
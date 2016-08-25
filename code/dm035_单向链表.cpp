/*
	实现单向链表的各项功能
*/

#include <stdio.h>
#include <stdlib.h>

#define TRAVERSEERROR -1
#define DELETEERROR -2
#define CLEARERROR -3

struct List{
	int data_;
	struct List* next_;
};

//创建链表
struct List* CreateList()
{
	return (struct List*)calloc(sizeof(struct List), 1);
}

//插入元素
struct List* InsertList(struct List* aList, int n, int data)
{
	struct List* p = aList;
	int i;
	for (i = 0; i < n; ++i)
	{
		p = p->next_;
	}

	if (!p)
	{
		return NULL;
	}

	struct List* newList = CreateList();
	newList->data_ = data;
	newList->next_ = p->next_;
	p->next_ = newList;

	return newList;
}

//遍历链表
int TraverseList(struct List* aList)
{
	struct List* p = aList;
	if (!p)
	{
		printf("链表为空\n");
		return TRAVERSEERROR;
	}

	while (p)
	{
		printf("%d\n", p->data_);
		p = p->next_;
	}
	return 0;
}

//删除链表
int DeleteList(struct List* aList, int n)
{
	struct List* p = aList;

	int i;
	for (i = 0; i < n; ++i)
	{
		p = p->next_;
	}

	if (!p)
	{
		printf("链表为空\n");
		return DELETEERROR;
	}

	struct List* deleteList = p->next_;
	p->next_ = p->next_->next_;
	free(deleteList);

	return 0;
}

//返回链表元素的个数
int CalcList(struct List* aList)
{
	int count = 0;
	while (aList)
	{
		aList = aList->next_;
		count++;
	}
	return count;
}

//清空链表保留首节点
int ClearList(struct List* aList)
{
	struct List* p = aList->next_;
	if (!aList || !p)
	{
		printf("链表为空\n");
		return CLEARERROR;
	}

	while (p)
	{
		struct List* tmp = p->next_;
		free(p);
		p = tmp;
	}

	aList->next_ = NULL;

	return 0;
}

//返回链表是否为空
int IsEmptyList(struct List* aList)
{
	if (aList->next_)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//返回链表指定的节点
struct List* LocaleList(struct List* aList, int n)
{
	struct List* p = aList;
	int i;
	for (i = 0; i < n; ++i)
	{
		p = p->next_;
	}

	if (p)
	{
		return p;
	}
	else
	{
		printf("链表不存在\n");
		return NULL;
	}
}

//返回数据域为data的节点
struct List* ElemList(struct List* aList, int data)
{
	struct List* p = aList;
	while (p)
	{
		if (p->data_ == data)
		{
			return p;
		}
		p = p->next_;
	}
	return NULL;
}

//返回数据域为data的节点的位置
int ElemLocate(struct List* aList, int data)
{
	int index = 0;
	struct List* p = aList;
	while (p)
	{
		if (p->data_ == data)
		{
			return index;
		}
		index++;
		p = p->next_;
	}
	return -1;
}

//得到链表最后一个节点
struct List* LastList(struct List* aList)
{
	struct List* p = aList;
	if (!p)
	{
		return NULL;
	}

	while (p->next_)
	{
		p = p->next_;
	}

	return p;
}

//合并两个链表
void MergeList(struct List* la, struct List* lb)
{
	struct List* p = LastList(la);
	p->next_ = lb->next_;
	free(lb);
}



//逆置链表
void Resever(struct List* la)
{
	if (la->next_ == NULL)
	{
		return;
	}
	struct List* last = la->next_;
	struct List* pre = la;
	struct List* cur = la->next_;
	struct List* next = NULL;

	while (cur)
	{
		next = cur->next_;
		cur->next_ = pre;
		pre = cur;
		cur = next;
	}

	la->next_ = pre;
	last->next_ = NULL;
}

int main()
{
	struct List* first = CreateList();
	first->data_ = 3;
	first->next_ = NULL;

	InsertList(first, 0, 1);
	InsertList(first, 1, 2);
	InsertList(first, 1, 3);
	InsertList(first, 1, 4);
	InsertList(first, 1, 5);

	struct List* second = CreateList();
	second->data_ = 10;
	second->next_ = NULL;
	InsertList(second, 0, 11);
	InsertList(second, 1, 12);
	MergeList(first, second);

	//DeleteList(first, 1);
	TraverseList(first);
	int value = CalcList(first);
	//ClearList(first);
	//TraverseList(first);

	if (IsEmptyList(first))
	{
		printf("链表不为空\n");
	}
	else
	{
		printf("链表为空\n");
	}

	printf("-------\n");
	struct List *res = LocaleList(first, 2);
	printf("%d\n", res->data_);

	res = ElemList(first, 4);
	printf("%d\n", res->data_);

	int index = ElemLocate(first, 4);
	printf("%d\n", index);

	res = LastList(first);
	printf("%d\n", res->data_);
	return 0;
}
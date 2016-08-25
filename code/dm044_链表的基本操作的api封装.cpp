/*
	通过API封装函数实现链表的增删改查
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memwatch.h"

typedef struct Node
{
	int data_;
	struct Node* next_;
}SLIST;

SLIST* CreatList()
{
	SLIST** pHead = NULL;
	SLIST* pCur = NULL;
	SLIST* pNew = NULL;
	int data;
	/*pHead = (SLIST*)malloc(sizeof(SLIST));
	pHead->data_ = 0;
	pHead->next_ = NULL;*/
	/*二级指针作为头节点*/
	pHead = (SLIST**)malloc(sizeof(SLIST*));

	printf("enter: ");
	scanf("%d", &data);
	
	/*头节点指向创建的第一个节点*/
	pCur = (SLIST*)malloc(sizeof(SLIST));
	if (!pCur)
	{
		printf("创建失败\n");
		return NULL;
	}
	pCur->data_ = data;
	pCur->next_ = NULL;

	*pHead = pCur;
	
	while (1)
	{
		printf("enter: ");
		scanf("%d", &data);
		if (data == -1)
		{
			break;
		}

		/*创建新的节点*/
		pNew = (SLIST*)malloc(sizeof(SLIST));
		if (!pNew)
		{
			printf("创建失败\n");
			break;
		}
		pNew->data_ = data;
		pNew->next_ = NULL;

		pCur->next_ = pNew;
		pCur = pNew;
	}

	pCur = *pHead;
	free(pHead);
	pHead = NULL;

	return pCur;
}

int PrintList(SLIST* pList)
{
	if (!pList)
	{
		return -1;
	}

	SLIST* tList = pList;

	while (tList)
	{
		printf("%d ", tList->data_);
		tList = tList->next_;
	}
	printf("\n");

	return 0;
}

/*从x后插入y，如果没有则在链表后面插入*/
int InsertList(SLIST* pList, int value, int data)
{
	SLIST* pPre = NULL;
	SLIST* pCur = NULL;
	//pPre = (SLIST*)malloc(sizeof(SLIST));
	//pCur = (SLIST*)malloc(sizeof(SLIST));

	pPre = pList;
	pCur = pList->next_;

	while (pCur)
	{
		if (pCur->data_ == value)
		{
			SLIST* pTmp = NULL;
			pTmp = (SLIST*)malloc(sizeof(SLIST));
			if (!pTmp)
			{
				printf("分配失败\n");
				return -1;
			}

			/*执行插入操作*/
			pTmp->data_ = data;
			pTmp->next_ = pCur->next_;
			pCur->next_ = pTmp;
			return 0;
		}
		pPre = pCur;
		pCur = pCur->next_;
	}

	SLIST* pTmp = NULL;
	pTmp = (SLIST*)malloc(sizeof(SLIST));
	pTmp->data_ = data;
	pTmp->next_ = NULL;
	pPre->next_ = pTmp;

	return 0;
}

int DeleteList(SLIST* pList, int data)
{
	SLIST* pCur = NULL;
	SLIST* pPre = NULL;
	pPre = pList;
	pCur = pList->next_;
	while (pCur)
	{
		if (pCur->data_ == data)
		{
			//删除节点
			SLIST* tmp = NULL;
			tmp = pCur;
			pPre->next_ = pCur->next_;
			pCur = pCur->next_;
			free(tmp); 
			tmp = NULL;
			return 0;
		}
		pPre = pCur;
		pCur = pCur->next_;
	}

	printf("该节点不存在\n");
	return 0;

}

/*销毁链表*/
int DestoryList(SLIST* pList)
{

	SLIST* pCur = NULL;
	SLIST* tmp = NULL;
	SLIST** pHead = &pList;
	pCur = pList;

	while (pCur)
	{
		tmp = pCur;
		pCur = pCur->next_;
		free(tmp);
		tmp = NULL;
	}

	return 0;

}

//逆置链表（因为没有头节点，所以需要把pList的地址传进来）
int InverseList(SLIST** pList)
{

	SLIST* pCur = NULL;
	SLIST* pPre = NULL;
	SLIST* pNext = NULL;

	pPre = *pList;

	pCur = pPre->next_;
	if (!pPre || !pCur)
	{
		return -1;
	}

	while (pCur)
	{
		pNext = pCur->next_;
		pCur->next_ = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	(*pList)->next_ = NULL;

	*pList = pPre;
	return 0;
	
}

int main()
{
	SLIST* myList = NULL;
	myList = CreatList();
	PrintList(myList);
	InsertList(myList, 5, 6);
	PrintList(myList);
	DeleteList(myList, 6);
	PrintList(myList);
	InverseList(&myList);
	PrintList(myList);
	DestoryList(myList);
	return 0;
}
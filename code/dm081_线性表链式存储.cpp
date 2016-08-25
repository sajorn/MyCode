#include <iostream>
#include <cstdlib>
using namespace std;

typedef void LinkList;

typedef struct stLinkListNode{
	struct stLinkListNode* pNext;
}LinkListNode;

typedef struct stLinkList{
	LinkListNode head;
	int length;
}TLinkList; 

LinkList* CreateList() //创建一个链表 
{
	TLinkList* tList = NULL;
	tList = new TLinkList;
	if (tList == NULL)
	{
		cout << "New List Error" << endl;
		return NULL;
	}
	tList->head.pNext = NULL;
	tList->length = 0;
	return tList;
}

int GetListLength(LinkList* pList) //获取链表的长度 
{
	TLinkList* tList = NULL;
	tList = (TLinkList*)pList;
	if (tList == NULL)
	{
		cout << "Get Length Error" << endl;
		return -1;
	}
	return tList->length;
}

int InsertListElem(LinkList* pList, LinkListNode* pNode, int pos) //插入元素
{
	if (pList == NULL || pNode == NULL || pos < 0)
	{
		cout << "Insert Error" << endl;
		return -1;
	}
	
	TLinkList* tList = NULL;
	LinkListNode* tCurNode = NULL;
	tList = (TLinkList*)pList;
	tCurNode = &(tList->head);
	
	for (int i = 0; i < pos && tCurNode->pNext != NULL; ++i)
	{
		tCurNode = tCurNode->pNext;
	}
	
	//插入算法 
	pNode->pNext = tCurNode->pNext;
	tCurNode->pNext = pNode;
	
	tList->length++;
	
	return 0;
} 

LinkList* GetListElem(LinkList* pList, int pos) //获取链表节点的元素
{
	if (pList == NULL || pos < 0)
	{
		cout << "Get Elem Error" << endl;
		return NULL;
	}
	
	TLinkList* tList = NULL;
	LinkListNode* tCurNode = NULL;
	tList = (TLinkList*)pList;
	tCurNode = &(tList->head);
	
	for (int i = 0; i < pos && tCurNode->pNext != NULL; ++i)
	{
		tCurNode = tCurNode->pNext;
	}
	
	return tCurNode->pNext;
} 

void DestoryList(LinkList* pList) //销毁链表
{
	if (pList != NULL)
	{
		delete pList;
		pList = NULL;	
	}	
} 

LinkList* DeleteList(LinkList* pList, int pos) //删除链表节点的元素
{
	TLinkList* tList = NULL;
	LinkListNode* curNode = NULL; //当前的节点 
	LinkListNode* delNode = NULL; //缓存要删除的节点
	if (pList == NULL || pos < 0)
	{
		cout << "Delete Error" << endl;
		return NULL;
	}
	tList = (TLinkList*)pList;
	curNode = &(tList->head);
	for (int i = 0; i < pos && curNode->pNext != NULL; ++i)
	{
		curNode = curNode->pNext;
	}
	
	//删除算法
	delNode = curNode->pNext;
	curNode->pNext = delNode->pNext; 
	
	tList->length--;
	
	return delNode;
} 

void ClearList(LinkList* pList) //清空链表，回复到初始的状态 
{
	TLinkList* tList = NULL;
	tList = (TLinkList*)pList;
	if (tList == NULL)
	{
		cout << "Clear Error" << endl;
		return;
	}
	tList->head.pNext = NULL;
	tList->length = 0; 
} 

//测试框架
typedef struct stTeacher{
	LinkListNode node;
	char name[32];
	int age;
}Teacher; 

int main()
{
	Teacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;
	
	LinkList* list = NULL;
	list = CreateList();
	if (list == NULL)
	{
		cout << "create error" << endl;
		return -1;
	}
	
	//插入
	InsertListElem(list, (LinkListNode*)&t1, 0);
	InsertListElem(list, (LinkListNode*)&t2, 0);
	InsertListElem(list, (LinkListNode*)&t3, 0);
	InsertListElem(list, (LinkListNode*)&t4, 0);
	InsertListElem(list, (LinkListNode*)&t5, 0);
	
	int len = GetListLength(list);
	
	//遍历 
	for (int i = 0; i < len; ++i)
	{
		Teacher* tmp = (Teacher*)GetListElem(list, i);
		cout << "Age: " << tmp->age << endl;
	}
	
	//删除节点
	while (len > 0)
	{
		DeleteList(list, 0);
		len--;
	}
	return 0;
}

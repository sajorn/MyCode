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

LinkList* CreateList() //����һ������ 
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

int GetListLength(LinkList* pList) //��ȡ����ĳ��� 
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

int InsertListElem(LinkList* pList, LinkListNode* pNode, int pos) //����Ԫ��
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
	
	//�����㷨 
	pNode->pNext = tCurNode->pNext;
	tCurNode->pNext = pNode;
	
	tList->length++;
	
	return 0;
} 

LinkList* GetListElem(LinkList* pList, int pos) //��ȡ����ڵ��Ԫ��
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

void DestoryList(LinkList* pList) //��������
{
	if (pList != NULL)
	{
		delete pList;
		pList = NULL;	
	}	
} 

LinkList* DeleteList(LinkList* pList, int pos) //ɾ������ڵ��Ԫ��
{
	TLinkList* tList = NULL;
	LinkListNode* curNode = NULL; //��ǰ�Ľڵ� 
	LinkListNode* delNode = NULL; //����Ҫɾ���Ľڵ�
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
	
	//ɾ���㷨
	delNode = curNode->pNext;
	curNode->pNext = delNode->pNext; 
	
	tList->length--;
	
	return delNode;
} 

void ClearList(LinkList* pList) //��������ظ�����ʼ��״̬ 
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

//���Կ��
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
	
	//����
	InsertListElem(list, (LinkListNode*)&t1, 0);
	InsertListElem(list, (LinkListNode*)&t2, 0);
	InsertListElem(list, (LinkListNode*)&t3, 0);
	InsertListElem(list, (LinkListNode*)&t4, 0);
	InsertListElem(list, (LinkListNode*)&t5, 0);
	
	int len = GetListLength(list);
	
	//���� 
	for (int i = 0; i < len; ++i)
	{
		Teacher* tmp = (Teacher*)GetListElem(list, i);
		cout << "Age: " << tmp->age << endl;
	}
	
	//ɾ���ڵ�
	while (len > 0)
	{
		DeleteList(list, 0);
		len--;
	}
	return 0;
}

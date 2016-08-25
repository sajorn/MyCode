#include <iostream>
using namespace std;

typedef void LinkQueue;
typedef void LinkQueueElem;

typedef struct stLinkQueueNode //队列链表业务结点
{
	stLinkQueueNode *pNext;
	LinkQueueElem* elem;
}LinkQueueNode;

typedef struct stLinkQueue //队列模型
{
	LinkQueueNode head;
	int length;
}TLinkQueue;

LinkQueue* CreateLinkQueue()
{
	TLinkQueue* tQueue = nullptr;
	tQueue = new TLinkQueue;
	tQueue->head.pNext = nullptr;
	tQueue->length = 0;
	return tQueue;
}


int InsertLinkQueue(LinkQueue* pQueue, LinkQueueElem* pElem)
{
	TLinkQueue* tQueue = nullptr;
	tQueue = (TLinkQueue*)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Insert Error" << endl;
		return -1;
	}
	LinkQueueNode* curNode = &(tQueue->head);
	for (int i = 0; i < tQueue->length; ++i)
	{
		curNode = curNode->pNext;
	}

	LinkQueueNode* newNode = new LinkQueueNode;
	newNode->elem = pElem;
	newNode->pNext = nullptr;
	curNode->pNext = newNode;

	tQueue->length++;
	return 0;
}

LinkQueueElem* DeleteLinkQueue(LinkQueue* pQueue)
{
	TLinkQueue* tQueue = nullptr;
	tQueue = (TLinkQueue*)pQueue;
	if (tQueue == nullptr || tQueue->length == 0)
	{
		cout << "Delete Error" << endl;
		return tQueue;
	}
	LinkQueueNode* delNode = tQueue->head.pNext;
	LinkQueueElem* delElem = tQueue->head.pNext->elem;

	tQueue->head.pNext = tQueue->head.pNext->pNext;
	
	delete delNode;
	tQueue->length--;
	return delElem;
}

void ClearLinkQueue(LinkQueue* pQueue)
{
	TLinkQueue* tQueue = nullptr;
	tQueue = (TLinkQueue *)pQueue;
	while (tQueue->length > 0)
	{
		DeleteLinkQueue(tQueue);
	}
	tQueue->head.pNext = nullptr;
	tQueue->length = 0;
}

void DestoryLinkQueue(LinkQueue* pQueue)
{
	ClearLinkQueue(pQueue);
	if (pQueue)
	{
		delete pQueue;
		pQueue = nullptr;
	}
}

int GetLinkQueueLength(LinkQueue* pQueue)
{
	TLinkQueue *tQueue = nullptr;
	tQueue = (TLinkQueue *)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Get Length Error" << endl;
		return -1;
	}
	return tQueue->length;
}

LinkQueueElem* GetLinkQueueHeader(LinkQueue* pQueue)
{
	TLinkQueue *tQueue = nullptr;
	tQueue = (TLinkQueue *)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Get Header Error" << endl;
		return tQueue;
	}
	LinkQueueElem* tmp = nullptr;
	tmp = (LinkQueueElem *)tQueue->head.pNext->elem;
	return tmp;
}

//测试框架
int main()
{
	int a[5];
	LinkQueue* queue = nullptr;
	queue = CreateLinkQueue();
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i + 1;
		InsertLinkQueue(queue, &a[i]);
	}
	int len = GetLinkQueueLength(queue);
	cout << "Len: " << len << endl;
	cout << "head: " << *((int*)GetLinkQueueHeader(queue)) << endl;

	while (len > 0)
	{
		cout << *((int*)DeleteLinkQueue(queue)) << " ";
		len--;
	}
	cout << endl;
	DestoryLinkQueue(queue);
	return 0;
}
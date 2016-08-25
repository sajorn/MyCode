#include <iostream>
using namespace std;

typedef void SeqQueue;
typedef void SeqQueueElem;

typedef struct stQueue
{
	int length;
	int capacity;
	unsigned *node;
}TQueue;

SeqQueue* CreateQueue(int _capacity)
{
	TQueue* tQueue = nullptr;
	tQueue = new TQueue;
	if (tQueue == nullptr)
	{
		cout << "Create Queue!" << endl;
		return tQueue;
	}
	tQueue->node = new unsigned[_capacity];
	tQueue->length = 0;
	tQueue->capacity = _capacity;

	return tQueue;
}

void ClearQueue(SeqQueue* pQueue)
{
	TQueue *tQueue = nullptr;
	tQueue = (TQueue *)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Clear Error!" << endl;
		return;
	}

	tQueue->length = 0;

}

void DestoryQueue(SeqQueue* pQueue)
{
	TQueue* tQueue = nullptr;
	tQueue = (TQueue*)pQueue;
	ClearQueue(tQueue);
	tQueue->capacity = 0;
	if (tQueue->node)
	{
		delete tQueue->node;
		tQueue->node = nullptr;
	}
	if (tQueue)
	{
		delete tQueue;
		tQueue = nullptr;
	}
}

void InsertQueue(SeqQueue* pQueue, SeqQueueElem* pElem)
{
	TQueue* tQueue = nullptr;
	tQueue = (TQueue*)pQueue;
	if (tQueue == nullptr || tQueue->length >= tQueue->capacity)
	{
		cout << "Insert Err" << endl;
		return;
	}
	tQueue->node[tQueue->length] = (unsigned)pElem;
	tQueue->length++;
}

SeqQueueElem* GetQueueHeader(SeqQueue* pQueue)
{
	TQueue* tQueue = nullptr;
	tQueue = (TQueue*)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Get Header Err" << endl;
		return nullptr;
	}
	SeqQueueElem* tmp = nullptr;
	tmp = (SeqQueueElem*)tQueue->node[0];
	return tmp;
}

SeqQueueElem* DeleteQueue(SeqQueue* pQueue)
{
	TQueue* tQueue = nullptr;
	tQueue = (TQueue*)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Delete Queue Err" << endl;
		return nullptr;
	}
	SeqQueueElem* tmp = nullptr;
	tmp = (SeqQueueElem*)tQueue->node[0];
	for (int i = 0; i < tQueue->length; ++i)
	{
		tQueue->node[i] = tQueue->node[i + 1];
	}
	tQueue->length--;
	return tmp;
}

int GetQueueLength(SeqQueue* pQueue)
{
	TQueue* tQueue = nullptr;
	tQueue = (TQueue*)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Get Length Err" << endl;
		return -1;
	}
	return tQueue->length;
}

int GetQueueCapacity(SeqQueue* pQueue)
{
	TQueue* tQueue = nullptr;
	tQueue = (TQueue*)pQueue;
	if (tQueue == nullptr)
	{
		cout << "Get Capacity Err" << endl;
		return -1;
	}
	return tQueue->capacity;
}

int main()
{
	SeqQueue *queue = nullptr;
	queue = CreateQueue(10);
	int a[5];
	for (int i = 0; i < 5; ++i)
	{
		a[i] = i + 1;
		InsertQueue(queue, &a[i]);
	}
	int len = GetQueueLength(queue);
	cout << "Len: " << len << endl;
	cout << "Head: " << *((int*)GetQueueHeader(queue)) << endl;
	cout << "Capacity: " << GetQueueCapacity(queue) << endl;

	while (len > 0)
	{
		cout << *((int*)DeleteQueue(queue)) << " ";
		len--;
	}
	cout << endl;
	DestoryQueue(queue);
	return 0;
}
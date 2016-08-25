#include <iostream>
using namespace std;

typedef struct stQueue
{
	int size; //队列容量
	int* head; //首元素地址
	int* tail; //尾元素地址
	int* base; //队列的基址
}TQueue;

int InitQueue(TQueue* pQueue, int nSize) //初始化
{
	if (pQueue == nullptr)
	{
		return -1;
	}

	pQueue->base = new int[nSize];
	pQueue->size = nSize;
	pQueue->head = nullptr;
	pQueue->tail = nullptr;
	return 0;
}

int push(TQueue* pQueue, int elem) //插入元素
{
	if (pQueue == nullptr)
	{
		return -1;
	}
	//插入第一个元素
	if (pQueue->head == nullptr)
	{
		pQueue->head = pQueue->base;
		pQueue->tail = pQueue->base;
		*(pQueue->tail) = elem;
		return 0;
	}

	/*tail插到尾部之后，就进行循环，移到基址的位置*/
	pQueue->tail++;
	if (pQueue->tail == pQueue->base + pQueue->size) //如果tail移到末尾
	{
		pQueue->tail = pQueue->base; //tail移动到基址位置
	}

	if (pQueue->tail == pQueue->head) //判断是否队列满了
	{
		//尾部指针回滚到移动前状态
		if (pQueue->tail == pQueue->base)
		{
			pQueue->tail = pQueue->base + pQueue->size - 1;
		}
		else
		{
			pQueue->tail--;
		}
		cout << "队列满了" << endl;
		return -1;
	}
	else
	{
		*(pQueue->tail) = elem;
	}
	return 0;
}

int Pop(TQueue* pQueue)
{
	if (pQueue == nullptr)
	{
		return -1;
	}

	//如果只有一个元素
	if (pQueue->head == pQueue->tail)
	{
		pQueue->head = nullptr;
		pQueue->tail = nullptr;
		return 0;
	}

	pQueue->head++;
	if (pQueue->head == pQueue->base + pQueue->size)
	{
		pQueue->head = pQueue->base;
	}


	return 0;
}

int size(TQueue* pQueue)
{
	if (pQueue == nullptr)
	{
		return -1;
	}
	int len = pQueue->tail - pQueue->head;
	if (len < 0)
	{
		len += pQueue->size;
	}
	return len;
}

int top(TQueue* pQueue)
{
	return *(pQueue->head);
}

int tail(TQueue* pQueue)
{
	return *(pQueue->tail);
}

bool empty(TQueue* pQueue)
{
	return (pQueue->head == nullptr);
}

int destory(TQueue* pQueue)
{
	if (pQueue->base)
	{
		delete[]pQueue->base;
		pQueue->base = nullptr;
	}
	if (pQueue)
	{
		delete pQueue;
		pQueue = nullptr;
	}
	pQueue->head = nullptr;
	pQueue->tail = nullptr;
	pQueue->size = 0;
	return 0;
}

//Text
int main()
{
	int arr[] = { 1, 3, 5, 7, 8, 9 };
	TQueue* queue = new TQueue;
	int len = sizeof(arr) / sizeof(int);
	InitQueue(queue, len);
	for (int i = 0; i < len; ++i)
	{
		push(queue, arr[i]);
	}
	for (int i = 0; i < 3; ++i)
	{
		Pop(queue);
	}
	for (int i = 0; i < 2; ++i)
	{
		push(queue, i*10);
	}

	while (!empty(queue))
	{
		cout << top(queue) << " ";
		Pop(queue);
	}

	destory(queue);
	return 0;
}
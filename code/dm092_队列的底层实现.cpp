#include <iostream>
using namespace std;

typedef struct stQueue
{
	int size; //��������
	int* head; //��Ԫ�ص�ַ
	int* tail; //βԪ�ص�ַ
	int* base; //���еĻ�ַ
}TQueue;

int InitQueue(TQueue* pQueue, int nSize) //��ʼ��
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

int push(TQueue* pQueue, int elem) //����Ԫ��
{
	if (pQueue == nullptr)
	{
		return -1;
	}
	//�����һ��Ԫ��
	if (pQueue->head == nullptr)
	{
		pQueue->head = pQueue->base;
		pQueue->tail = pQueue->base;
		*(pQueue->tail) = elem;
		return 0;
	}

	/*tail�嵽β��֮�󣬾ͽ���ѭ�����Ƶ���ַ��λ��*/
	pQueue->tail++;
	if (pQueue->tail == pQueue->base + pQueue->size) //���tail�Ƶ�ĩβ
	{
		pQueue->tail = pQueue->base; //tail�ƶ�����ַλ��
	}

	if (pQueue->tail == pQueue->head) //�ж��Ƿ��������
	{
		//β��ָ��ع����ƶ�ǰ״̬
		if (pQueue->tail == pQueue->base)
		{
			pQueue->tail = pQueue->base + pQueue->size - 1;
		}
		else
		{
			pQueue->tail--;
		}
		cout << "��������" << endl;
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

	//���ֻ��һ��Ԫ��
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
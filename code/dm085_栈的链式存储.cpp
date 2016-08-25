#include <iostream>
using namespace std;

typedef void LinkStack;
typedef void LinkStackElem;

typedef struct stLinkStackNode
{
	struct stLinkStackNode* pNext;
	LinkStackElem* Elem; //栈的业务节点元素
}TLinkStackNode;

typedef struct stLinkStack
{
	TLinkStackNode pHead;
	int size;
}TLinkStack;

//创建栈
LinkStack* CreateLinkStack()
{
	TLinkStack* tStack = nullptr;
	tStack = new TLinkStack;
	if (tStack == nullptr)
	{
		cout << "Create Error!" << endl;
		return tStack;
	}
	tStack->pHead.pNext = nullptr;
	tStack->size = 0;

	return tStack;
}


//入栈
int PushLinkStack(LinkStack* pStack, LinkStackElem* pElem)
{
	TLinkStack* tStack = nullptr;
	tStack = (TLinkStack*)pStack;
	if (tStack == nullptr && pElem == nullptr)
	{
		cout << "Push Err" << endl;
		return -1;
	}
	TLinkStackNode* curNode = tStack->pHead.pNext;
	TLinkStackNode* newNode = new TLinkStackNode;
	newNode->Elem = pElem;

	newNode->pNext = curNode;
	tStack->pHead.pNext = newNode;

	tStack->size++;
	return 0;
}

//出栈
LinkStackElem* PopLinkStack(LinkStack* pStack)
{
	TLinkStack* tStack = nullptr;
	tStack = (TLinkStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "Push Err" << endl;
		return nullptr;
	}

	TLinkStackNode* delNode = tStack->pHead.pNext;
	tStack->pHead.pNext = tStack->pHead.pNext->pNext;
	
	tStack->size--;
	LinkStackElem* tElem = nullptr;
	tElem = delNode->Elem;
	delete delNode;
	return tElem;
}

//返回栈顶元素
LinkStackElem* GetTopElem(LinkStack* pStack)
{
	TLinkStack* tStack = nullptr;
	tStack = (TLinkStack*)pStack;
	TLinkStackNode* tNode = nullptr;
	tNode = (TLinkStackNode*)tStack->pHead.pNext;
	return tNode->Elem;

}

//返回栈的长度
int GetLinkStackLength(LinkStack* pStack)
{
	TLinkStack* tStack = nullptr;
	tStack = (TLinkStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "GetLength Error" << endl;
		return -1;
	}
	return tStack->size;
}


//清空栈
int ClearLinkStack(LinkStack* pStack)
{
	TLinkStack* tStack = nullptr;
	tStack = (TLinkStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "Clear Error!" << endl;
		return -1;
	}
	while (tStack->size > 0)
	{
		PopLinkStack(pStack);
	}
	tStack->pHead.pNext = nullptr;
	tStack->size = 0;
	return 0;
}

//销毁栈
int DestoryLinkStack(LinkStack* pStack)
{
	ClearLinkStack(pStack);
	if (pStack)
	{
		delete pStack;
		pStack = nullptr;
	}
	return 0;
}

typedef struct stTeacher
{
	
}Teacher;

int main()
{
	int a[5];
	LinkStack* myStack = nullptr;
	myStack = CreateLinkStack();
	if (myStack == nullptr)
	{
		return 0;
	}

	for (int i = 0; i < 5; ++i)
	{
		a[i] = i + 1;
		PushLinkStack(myStack, &a[i]);
		cout << "INPUT: " << a[i] << " ";
	}
	cout << endl;

	int len = GetLinkStackLength(myStack);
	cout << "Length: " << len << ", Top: " << *((int*)GetTopElem(myStack)) << endl;

	while (len--)
	{
		cout << "POP: " << *((int*)PopLinkStack(myStack)) << " ";
	}

	DestoryLinkStack(myStack);
	return 0;
}
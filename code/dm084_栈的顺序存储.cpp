#include <iostream>
using namespace std;

typedef void SeqStack; //ջģ��
typedef void SeqStackElem; //ջԪ��

typedef struct stStack{
	int length;
	int capacity;
	unsigned* node;
}TStack;

SeqStack* CreateStack(int _capacity) //����ջ �൱�ڴ���һ�����Ա�
{
	TStack* tStack = nullptr;
	tStack = new TStack;
	if (tStack == nullptr)
	{
		cout << "Create Stack Err" << endl;
		return tStack;
	}

	tStack->node = new unsigned[_capacity];
	if (tStack->node == nullptr)
	{
		cout << "Create Node Err" << endl;
		return tStack->node;
	}

	tStack->capacity = _capacity;
	tStack->length = 0;
	return tStack;
}

void DestoryStack(SeqStack* pStack) //����ջ
{
	TStack* tStack = nullptr;
	tStack = (TStack*)pStack;

	if (tStack->node)
	{
		delete tStack->node;
		tStack->node = nullptr;
	}

	if (tStack)
	{
		delete tStack;
		tStack->node = nullptr;
	}
	tStack->length = 0;
	tStack->capacity = 0;
}

void ClearStack(SeqStack* pStack) //���ջ
{
	TStack* tStack = nullptr;
	tStack = (TStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "Clear Err" << endl;
		return;
	}

	tStack->length = 0;
}

int PushStack(SeqStack* pStack, SeqStackElem* pElem) //��ջ ���Ա��β������
{
	TStack* tStack = nullptr;
	tStack = (TStack*)pStack;
	if (tStack == nullptr || pElem == nullptr)
	{
		cout << "Push Err" << endl;
		return -1;
	}

	if (tStack->length >= tStack->capacity)
	{
		cout << "Push Full" << endl;
		return -1;
	}

	tStack->node[tStack->length] = (unsigned)pElem;
	tStack->length++;
	return 0;
}

SeqStackElem* PopStack(SeqStack* pStack) //��ջ
{
	TStack* tStack = nullptr;
	tStack = (TStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "Pop Err" << endl;
		return tStack;
	}

	SeqStackElem* delStackElem = nullptr;
	delStackElem = (SeqStackElem*)tStack->node[tStack->length - 1];
	tStack->length--;
	return delStackElem;
}

SeqStackElem* GetStackTopElem(SeqStack* pStack) //��ȡջ��Ԫ��
{
	TStack* tStack = nullptr;
	tStack = (TStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "Get Top Elem Err" << endl;
		return tStack;
	}

	return (SeqStackElem*)tStack->node[tStack->length - 1];
}

int GetStackLength(SeqStack* pStack) //��ȡջ�ĳ���
{
	TStack* tStack = nullptr;
	tStack = (TStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "Get Length Err" << endl;
		return -1;
	}

	return tStack->length;
}

int GetStackCapacity(SeqStack* pStack) //��ȡջ������
{
	TStack* tStack = nullptr;
	tStack = (TStack*)pStack;
	if (tStack == nullptr)
	{
		cout << "Get Capacity Err" << endl;
		return -1;
	}

	return tStack->capacity;
}

int main()
{
	int a[10]; 
	SeqStack* stack;
	stack = CreateStack(10);

	for (int i = 0; i < 5; ++i)
	{
		a[i] = i + 1;
		PushStack(stack, &a[i]);
	}

	cout << "Capacity: " << GetStackCapacity(stack) << endl;
	cout << "Length: " << GetStackLength(stack) << endl;
	cout << "TopElem: " << *(int*)GetStackTopElem(stack) << endl;
	
	while (GetStackLength(stack) > 0)
	{
		cout << "Pop Elem: " << *(int*)PopStack(stack) << " ";
	}

	cout << endl;
	return 0;
}
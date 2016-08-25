#include <iostream>
using namespace std;

typedef void SeqList;
typedef void SeqListNode;

typedef struct stSeqList
{
	int length; //��ǰ����
	int capacity; //����
	unsigned* node;
}TSeqList;

SeqList* CreateList(int _capacity)
{
	TSeqList* tmp; 
	tmp = new TSeqList;
	if (tmp == nullptr)
	{
		cout << "new TSeqList error" << endl;
		return nullptr;
	}
	tmp->node = new unsigned[_capacity];
	//tmp->node = (unsigned*)malloc(sizeof(unsigned*) * _capacity);
	if (tmp->node == nullptr)
	{
		cout << "new node error" << endl;
		return nullptr;
	}
	tmp->capacity = _capacity;
	tmp->length = 0;

	return tmp;
}

void DistoryList(SeqList* sqList)
{
	TSeqList* tList = nullptr;
	if (sqList == nullptr)
	{
		cout << "����ʧ��" << endl;
		return;
	}

	tList = (TSeqList*)sqList; 
	if (tList->node)
	{
		delete[] tList->node;
		tList->node = nullptr;
	}
	if (tList)
	{
		delete tList;
		tList = nullptr;
	}
	return;
}

void ClearList(SeqList* sqList)
{
	TSeqList* tList = nullptr;
	if (sqList == nullptr)
	{
		cout << "Clear error" << endl;
		return;
	}
	tList = (TSeqList*)sqList;
	tList->length = 0;
	return;
}

int GetListIndex(SeqList* sqList)
{
	TSeqList* tList = nullptr;
	if (sqList == nullptr)
	{
		cout << "Clear error" << endl;
		return -1;
	}
	tList = (TSeqList*)sqList;
	return tList->capacity;
}

int GetListLength(SeqList* sqList)
{
	TSeqList* tList = nullptr;
	if (sqList == nullptr)
	{
		cout << "Clear error" << endl;
		return -1;
	}
	tList = (TSeqList*)sqList;
	return tList->length;
}

int InsertElem(SeqList* sqList, SeqListNode* sqNode, int pos)
{
	if (sqList == nullptr || sqNode == nullptr || pos < 0)
	{
		cout << "list and node = null or pos < 0" << endl;
		return -1;
	}
	TSeqList* tList = nullptr;
	tList = (TSeqList*)sqList;

	//�ж��Ƿ�����
	if (tList->length >= tList->capacity)
	{
		cout << "full of list" << endl;
		return -1;
	}

	//�ݴ���length < pos < capacity
	if (pos >= tList->length)
	{
		pos = tList->length;
	}

	//Ԫ�غ���
	for (int i = tList->length; i > pos; --i)
	{
		tList->node[i] = tList->node[i - 1];
	}

	tList->node[pos] = (unsigned)sqNode;

	tList->length++;
	return 0;
}

SeqListNode* GetListElem(SeqList* sqList, int pos)
{
	SeqListNode* tListNode = nullptr;
	TSeqList* tList = nullptr;
	if (sqList == nullptr || pos < 0)
	{
		cout << "error: list = null or pos < 0" << endl;
		return nullptr;
	}
	tList = (TSeqList*)sqList;
	tListNode = (SeqListNode*)tList->node[pos];
	return tListNode;
}

SeqListNode* DeleteListElem(SeqList* sqList, int pos)
{
	TSeqList* tList = nullptr;
	SeqListNode* tNode = nullptr;

	if (sqList == nullptr || pos < 0)
	{
		cout << "list = null or pos < 0" << endl;
		return nullptr;
	}
	tList = (TSeqList*)sqList;
	tNode = (SeqListNode*)tList->node[pos];
	//ɾ��ָ��λ�õ�Ԫ��
	for (int i = pos + 1; i < tList->length; ++i)
	{
		tList->node[i - 1] = tList->node[i];
	}

	tList->length--;
	return tNode;
}

//���Կ��
struct stTeacher
{
	int age;
};

int main()
{
	stTeacher t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	SeqList* sqList = nullptr;
	sqList = CreateList(5); //����һ������Ϊ10�����Ա�

	//����Ԫ��
	InsertElem(sqList, &t1, 0);
	InsertElem(sqList, &t2, 0);
	InsertElem(sqList, &t3, 0);
	InsertElem(sqList, &t4, 0);
	InsertElem(sqList, &t5, 0);

	//����
	for (int i = 0; i < GetListLength(sqList); ++i)
	{
		stTeacher* tmp = (stTeacher*)GetListElem(sqList, i); // ��ȡ��i��Ԫ�ص�λ��
		cout << "Age: " << tmp->age << endl;
	}
	
	//ɾ��Ԫ��
	while (GetListLength(sqList) > 0)
	{
		DeleteListElem(sqList, 0);
	}

	return 0;
}
#include <iostream>
using namespace std;

typedef void SeqList;
typedef void SeqListNode;

typedef struct stSeqList
{
	int length; //当前长度
	int capacity; //容量
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
		cout << "销毁失败" << endl;
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

	//判断是否满了
	if (tList->length >= tList->capacity)
	{
		cout << "full of list" << endl;
		return -1;
	}

	//容错，即length < pos < capacity
	if (pos >= tList->length)
	{
		pos = tList->length;
	}

	//元素后移
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
	//删除指定位置的元素
	for (int i = pos + 1; i < tList->length; ++i)
	{
		tList->node[i - 1] = tList->node[i];
	}

	tList->length--;
	return tNode;
}

//测试框架
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
	sqList = CreateList(5); //创建一个容量为10的线性表

	//插入元素
	InsertElem(sqList, &t1, 0);
	InsertElem(sqList, &t2, 0);
	InsertElem(sqList, &t3, 0);
	InsertElem(sqList, &t4, 0);
	InsertElem(sqList, &t5, 0);

	//遍历
	for (int i = 0; i < GetListLength(sqList); ++i)
	{
		stTeacher* tmp = (stTeacher*)GetListElem(sqList, i); // 获取第i个元素的位置
		cout << "Age: " << tmp->age << endl;
	}
	
	//删除元素
	while (GetListLength(sqList) > 0)
	{
		DeleteListElem(sqList, 0);
	}

	return 0;
}
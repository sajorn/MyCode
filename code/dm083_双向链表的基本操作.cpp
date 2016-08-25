#include <iostream>
using namespace std;

typedef void DLinkList;

//˫������Ľڵ�
typedef struct stDLinkListNode
{
	struct stDLinkListNode* pPre; //ǰһ���ڵ�
	struct stDLinkListNode* pNext; //��һ���ڵ�
}DLinkListNode;

//˫������
typedef struct stDLinkList
{
	DLinkListNode head; //ͷ�ڵ�
	DLinkListNode* pSliper; //�α�
	int length; //����
}TDLinkList;

//����һ���µ�����
DLinkList* CreateDLinkList()
{
	TDLinkList* tLink = nullptr;
	tLink = new TDLinkList;
	if (tLink == nullptr)
	{
		cout << "New Link Err" << endl;
		return tLink;
	}

	tLink->head.pNext = nullptr;
	tLink->head.pPre = nullptr;
	tLink->pSliper = nullptr;
	tLink->length = 0;
	return tLink;
}

//��������
void DestoryDLinkList(DLinkList* pList)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList)
	{
		delete tList;
	}
}

//�������
void ClearDLinkList(DLinkList* pList)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;

	if (tList == nullptr)
	{
		cout << "Clear Err" << endl;
		return;
	}

	tList->head.pNext = nullptr;
	tList->head.pPre = nullptr;
	tList->pSliper = nullptr;
	tList->length = 0;
}

//��ȡ������
int GetDLinkListLength(DLinkList* pList)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr)
	{
		cout << "GetLength Err" << endl;
		return -1;
	}

	return tList->length;
}

//�������
int InsertDLinkListElem(DLinkList* pList, DLinkListNode* pNode, int pos)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr || pNode == nullptr || pos < 0)
	{
		cout << "Insert Err" << endl;
		return -1;
	}

	DLinkListNode* curNode = &(tList->head);
	DLinkListNode* nextNode = nullptr;

	for (int i = 0; i < pos && curNode->pNext != nullptr; ++i)
	{
		curNode = curNode->pNext;
	}
	nextNode = curNode->pNext;

	//�����㷨
	curNode->pNext = pNode;
	pNode->pNext = nextNode;

	//����ǵ�һ���ڵ�
	if (nextNode != nullptr)
	{
		nextNode->pPre = pNode;
	}
	pNode->pPre = curNode;

	//�����һ���ڵ㴦���α�
	if (tList->length == 0)
	{
		tList->pSliper = pNode;
	}

	//ͷ�巨
	if (curNode == &(tList->head))
	{
		pNode->pPre = nullptr;
	}
	tList->length++;

	return 0;
}

//ͨ���±��ȡ�ڵ�
DLinkListNode* GetDLinkListElem(DLinkList* pList, int pos)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr || pos < 0)
	{
		cout << "Get Elem Err" << endl;
		return nullptr;
	}

	DLinkListNode* curNode = (DLinkListNode*)tList;
	for (int i = 0; i < pos; ++i)
	{
		curNode = curNode->pNext;
	}

	return curNode->pNext;
}

//ɾ���ڵ�
DLinkListNode* DeleteDLinkListElem(DLinkList* pList, int pos)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr || pos < 0)
	{
		cout << "Delete Pos Err" << endl;
		return nullptr;
	}

	DLinkListNode* curNode = &(tList->head);
	DLinkListNode* delNode = nullptr;
	DLinkListNode* nextNode = nullptr;

	for (int i = 0; i < pos && curNode->pNext != nullptr; ++i)
	{
		curNode = curNode->pNext;
	}
	nextNode = curNode->pNext->pNext;

	//ɾ���㷨
	delNode = curNode->pNext;
	curNode->pNext = nextNode;
	//�����һ��Ԫ��
	if (nextNode != nullptr)
	{
		nextNode->pPre = curNode;
		//�����0��λ��
		if (curNode == &(tList->head))
		{
			nextNode->pPre = nullptr;
		}
	}
	//�α꼴ɾ���ڵ�
	if (tList->pSliper == delNode)
	{
		tList->pSliper = delNode->pNext;
	}

	tList->length--;
	return delNode;
}

//ɾ��ָ���ڵ�
DLinkListNode* DeleteDLinkListNode(DLinkList* pList, DLinkListNode* pNode)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr || pNode == nullptr)
	{
		cout << "Delete Node Err" << endl;
		return nullptr;
	}

	DLinkListNode* curNode = (DLinkListNode*)tList;
	DLinkListNode* delNode = nullptr;
	for (int i = 0; i < tList->length; ++i)
	{
		curNode = curNode->pNext;
		if (curNode == pNode)
		{
			delNode = curNode;
			DeleteDLinkListElem(tList, i);
			break;
		}
	}

	return delNode;
}

//�����α�λ��
DLinkListNode* DLinkListSliderReset(DLinkList* pList)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr)
	{
		cout << "Reset Slider Err" << endl;
		return nullptr;
	}

	tList->pSliper = (&(tList->head))->pNext;
	return tList->pSliper;
}

//����α�λ�ã��α겻�ƶ�
DLinkList* GetDLinkListSliderCur(DLinkList* pList)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr || tList->pSliper == nullptr)
	{
		cout << "Delete Node Err" << endl;
		return nullptr;
	}

	return tList->pSliper;
}

//����α�λ�ã��α�����
DLinkList* GetLinkListSliderNext(DLinkList* pList)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr || tList->pSliper == nullptr)
	{
		cout << "Delete Node Err" << endl;
		return nullptr;
	}

	DLinkListNode* tSlider = nullptr;
	tSlider = tList->pSliper;
	tList->pSliper = tList->pSliper->pNext;

	return tSlider;
}

//����α�λ�ã��α�����
DLinkList* GetLinkListSliderPre(DLinkList* pList)
{
	TDLinkList* tList = nullptr;
	tList = (TDLinkList*)pList;
	if (tList == nullptr || tList->pSliper == nullptr)
	{
		cout << "Delete Node Err" << endl;
		return nullptr;
	}

	DLinkListNode* tSlider = nullptr;
	tSlider = tList->pSliper;
	tList->pSliper = tList->pSliper->pPre;

	return tSlider;
}

//���Կ��

typedef struct stValue
{
	DLinkListNode node;
	int v;
}Value;

int main()
{
	int i = 0;
	DLinkList* list = CreateDLinkList();
	Value* pv = NULL;
	Value v1, v2, v3, v4, v5;

	v1.v = 1;	v2.v = 2;	v3.v = 3;	v4.v = 4;	v5.v = 5;

	InsertDLinkListElem(list, (DLinkListNode*)&v1, GetDLinkListLength(list));
	InsertDLinkListElem(list, (DLinkListNode*)&v2, GetDLinkListLength(list));
	InsertDLinkListElem(list, (DLinkListNode*)&v3, GetDLinkListLength(list));
	InsertDLinkListElem(list, (DLinkListNode*)&v4, GetDLinkListLength(list));
	InsertDLinkListElem(list, (DLinkListNode*)&v5, GetDLinkListLength(list));

	for (i = 0; i < GetDLinkListLength(list); i++)
	{
		pv = (Value*)GetDLinkListElem(list, i);

		printf("%d\n", pv->v);
	}

	printf("\n");

	DeleteDLinkListElem(list, GetDLinkListLength(list) - 1);
	DeleteDLinkListElem(list, 0);
	//DLinkList_Delete(list, 3);


	for (i = 0; i < GetDLinkListLength(list); i++)
	{
		pv = (Value*)GetLinkListSliderNext(list);

		printf("%d\n", pv->v);
	}

	printf("\n");

	DLinkListSliderReset(list);
	GetLinkListSliderNext(list);

	pv = (Value*)GetDLinkListSliderCur(list);

	printf("%d\n", pv->v);

	DeleteDLinkListNode(list, (DLinkListNode*)pv);

	pv = (Value*)GetDLinkListSliderCur(list);

	printf("%d\n", pv->v);

	GetLinkListSliderPre(list);

	pv = (Value*)GetDLinkListSliderCur(list);

	printf("%d\n", pv->v);

	printf("Length: %d\n", GetDLinkListLength(list));

	DestoryDLinkList(list);
	return 0;
}
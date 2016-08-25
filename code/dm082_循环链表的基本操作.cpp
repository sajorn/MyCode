#include <iostream>
using namespace std;

typedef void CircleList;

//ѭ������Ľڵ�
typedef struct stCircleListNode
{
	stCircleListNode* pNext;
}CircleListNode;

//ѭ������
typedef struct stCircleList
{
	CircleListNode header; //����ͷ
	CircleListNode* slider; //�α�
	int length; //����
}TCircleList;

//��������
CircleList* CreateCircleList()
{
	TCircleList* tList = nullptr;
	tList = new TCircleList;
	if (tList == nullptr)
	{
		cout << "Create List Err" << endl;
		return nullptr;
	}
	tList->header.pNext = nullptr;
	tList->slider = nullptr;
	tList->length = 0;

	return tList;
}

//�������
void ClearCircleList(CircleList* pList)
{
	TCircleList* tList = nullptr;
	CircleListNode* delNode = nullptr; //ɾ���Ľڵ�
	CircleListNode* curNode = nullptr; //��ǰ�Ľڵ�

	curNode = (&(tList->header))->pNext;

	if (pList == nullptr)
	{
		cout << "Clear Err" << endl;
		return;
	}
	tList = (TCircleList*)pList;
// 	for (int i = 0; i < tList->length && curNode->pNext != nullptr; ++i)
// 	{
// 		delNode = curNode;
// 		curNode = curNode->pNext;
// 		delete delNode;
// 	}

	tList->header.pNext = nullptr;
	tList->slider = nullptr;
	tList->length = 0;
}

//��������
int DestoryCircleList(CircleList* pList)
{
	TCircleList* tList = nullptr;
	tList = (TCircleList*)pList;
	if (tList == nullptr)
	{
		cout << "Destory Error" << endl;
		return -1;
	}

	/*ClearCircleList(tList);*/

	if (tList)
	{
		delete tList;
		tList = nullptr;
	}
	return 0;
}



//��ȡ����ĳ���
int GetListLength(CircleList* pList)
{
	TCircleList* tList = nullptr;
	tList = (TCircleList*)pList;
	if (tList == nullptr)
	{
		cout << "Get Length Err" << endl;
		return -1;
	}
	
	return tList->length;
}

//��ȡ�ڵ��Ԫ��
CircleListNode* GetListElem(CircleList* pList, int pos)
{
	TCircleList* tList = nullptr;
	CircleListNode* curNode = nullptr;
	tList = (TCircleList*)pList;
	curNode = (CircleListNode*)tList;

	for (int i = 0; i < pos; ++i)
	{
		curNode = curNode->pNext;
	}

	return curNode->pNext;
}

//ָ��λ�ò���Ԫ��
void InsertCircleList(CircleList* pList, CircleListNode* pNode, int pos)
{
	if (pList == nullptr || pNode == nullptr || pos < 0)
	{
		cout << "Insert Err" << endl;
		return;
	}
	TCircleList* tList = (TCircleList*)pList;
	CircleListNode* curNode = &(tList->header);
	for (int i = 0; i < pos; ++i)
	{
		curNode = curNode->pNext;
	}

	//��ͨ�Ĳ���
	pNode->pNext = curNode->pNext;
	curNode->pNext = pNode;

	//��һ�β���ڵ�
	if (tList->length == 0)
	{
		tList->slider = pNode; //�α�ָ���һ���ڵ�
		
	}

	tList->length++;

	//�����ͷ�巨������ǰ�ڵ���Ȼ��ͷ���ڵ��ʱ��
	if (curNode == &(tList->header))
	{
		//��ȡβ���ڵ�
		CircleListNode* pLast = GetListElem(tList, tList->length - 1);
		pLast->pNext = curNode->pNext;
	}

}


//ɾ����Ӧ�±�Ľڵ�
CircleListNode* DeleteCircleList(CircleList* pList, int pos)
{
	TCircleList* tList = nullptr;
	tList = (TCircleList*)pList;

	CircleListNode* curNode = &(tList->header);
	CircleListNode* delNode = nullptr;

	//�ҵ�Ҫɾ�����±�λ��
	for (int i = 0; i < pos && curNode->pNext != nullptr; ++i)
	{
		curNode = curNode->pNext;
	}

	//��ȡ���һ���ڵ�
	CircleListNode* lastNode = nullptr;

	//ɾ��ͷ�ڵ㣬��ȡβ��Ԫ��
	if (curNode == &(tList->header))
	{
		lastNode = GetListElem(tList, tList->length - 1);
	}
	delNode = curNode->pNext;
	curNode->pNext = delNode->pNext;
	tList->length--;

	//�ж��Ƿ��ȡβ��Ԫ�أ����Ƿ�Ҫɾ�Ľڵ���ͷ�ڵ�
	if (lastNode != nullptr)
	{
		tList->header.pNext = delNode->pNext;
		lastNode->pNext = delNode->pNext; //��β��ָ��ָ��ɾ���ڵ����һ���ڵ�
	}

	//���ɾ�������α�Ľڵ�
	if (delNode == tList->slider)
	{
		tList->slider = delNode->pNext;
	}

	//���ɾ��Ԫ��֮�󳤶�Ϊ0
	if (tList->length == 0)
	{
		tList->header.pNext = nullptr;
		tList->slider = nullptr;
	}

	return delNode;
}

/*ɾ����Ӧ�Ľڵ�*/
CircleListNode* DeleteCircleListNode(CircleList* pList, CircleListNode* pNode)
{
	CircleListNode* delNode = nullptr;
	if (pList == nullptr || pNode == nullptr)
	{
		return delNode;
	}

	TCircleList* tList = nullptr;
	tList = (TCircleList*)pList;
	CircleListNode* curNode = nullptr;
	curNode = &(tList->header);

	int i;
	for (i = 0; i < tList->length; ++i)
	{
		if (curNode->pNext == pNode)
		{
			delNode = pNode;
			break;
		}
		curNode = curNode->pNext;
	}
	
	if (delNode != nullptr)
	{
		DeleteCircleList(tList, i);
	}

	return delNode;
}

//������α�����
CircleListNode* CircleListReset(CircleList* pList)
{
	TCircleList* tList = nullptr;
	CircleListNode* pSlider = nullptr;
	tList = (TCircleList*)pList;

	if (tList->slider != nullptr)
	{
		tList->slider = tList->header.pNext;
		pSlider = tList->slider;
	}
	return pSlider;
}

//��ȡ�α�ָ���λ��
CircleListNode* GetCurSlider(CircleList* pList)
{
	TCircleList* tList = nullptr;
	CircleListNode* pSlider = nullptr;
	tList = (TCircleList*)pList;

	if (tList->slider != nullptr)
	{
		pSlider = tList->slider;
	}

	return pSlider;
}

//���ص�ǰ�α�λ�ã��������α�����
CircleListNode* GetNextSlider(CircleList* pList)
{
	TCircleList* tList = nullptr;
	CircleListNode* pSlider = nullptr;
	tList = (TCircleList*)pList;

	if (tList != nullptr && tList->slider != nullptr)
	{
		pSlider = tList->slider;
		tList->slider = pSlider->pNext;
	}

	return pSlider;
}

typedef struct stValue
{
	CircleListNode node;
	int value;
}Value;

//���԰��� Լɪ����������
int main()
{
	CircleList* tList = nullptr;
	tList = CreateCircleList();

	Value v[8];
	for (int i = 0; i < 8; ++i)
	{
		v[i].value = i + 1;
		InsertCircleList(tList, (CircleListNode*)&v[i], GetListLength(tList));
	}

	for (int i = 0; i < GetListLength(tList) * 2; ++i)
	{
		Value* tmpValue = (Value*)GetNextSlider(tList);
		cout << "Value: " << tmpValue->value << " ";
	}
	cout << endl;

	CircleListReset(tList);

	while (GetListLength(tList) > 0)
	{
		Value* tmpValue = nullptr;
		for (int i = 1; i < 3; ++i)
		{
			GetNextSlider(tList);
		}
		tmpValue = (Value*)GetCurSlider(tList);
		cout << "Value: " << tmpValue->value << " ";
		DeleteCircleListNode(tList, (CircleListNode*)tmpValue);
	}

	DestoryCircleList(tList);

	return 0;
}
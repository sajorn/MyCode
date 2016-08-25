#include <iostream>
using namespace std;

typedef void CircleList;

//循环链表的节点
typedef struct stCircleListNode
{
	stCircleListNode* pNext;
}CircleListNode;

//循环链表
typedef struct stCircleList
{
	CircleListNode header; //链表头
	CircleListNode* slider; //游标
	int length; //长度
}TCircleList;

//创建链表
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

//清空链表
void ClearCircleList(CircleList* pList)
{
	TCircleList* tList = nullptr;
	CircleListNode* delNode = nullptr; //删除的节点
	CircleListNode* curNode = nullptr; //当前的节点

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

//销毁链表
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



//获取链表的长度
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

//获取节点的元素
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

//指定位置插入元素
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

	//普通的插入
	pNode->pNext = curNode->pNext;
	curNode->pNext = pNode;

	//第一次插入节点
	if (tList->length == 0)
	{
		tList->slider = pNode; //游标指向第一个节点
		
	}

	tList->length++;

	//如果是头插法，即当前节点仍然在头部节点的时候
	if (curNode == &(tList->header))
	{
		//获取尾部节点
		CircleListNode* pLast = GetListElem(tList, tList->length - 1);
		pLast->pNext = curNode->pNext;
	}

}


//删除相应下标的节点
CircleListNode* DeleteCircleList(CircleList* pList, int pos)
{
	TCircleList* tList = nullptr;
	tList = (TCircleList*)pList;

	CircleListNode* curNode = &(tList->header);
	CircleListNode* delNode = nullptr;

	//找到要删除的下标位置
	for (int i = 0; i < pos && curNode->pNext != nullptr; ++i)
	{
		curNode = curNode->pNext;
	}

	//获取最后一个节点
	CircleListNode* lastNode = nullptr;

	//删除头节点，获取尾部元素
	if (curNode == &(tList->header))
	{
		lastNode = GetListElem(tList, tList->length - 1);
	}
	delNode = curNode->pNext;
	curNode->pNext = delNode->pNext;
	tList->length--;

	//判断是否获取尾部元素，即是否要删的节点是头节点
	if (lastNode != nullptr)
	{
		tList->header.pNext = delNode->pNext;
		lastNode->pNext = delNode->pNext; //把尾部指针指向删除节点的下一个节点
	}

	//如果删除的是游标的节点
	if (delNode == tList->slider)
	{
		tList->slider = delNode->pNext;
	}

	//如果删除元素之后长度为0
	if (tList->length == 0)
	{
		tList->header.pNext = nullptr;
		tList->slider = nullptr;
	}

	return delNode;
}

/*删除相应的节点*/
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

//链表的游标重置
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

//获取游标指向的位置
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

//返回当前游标位置，并且让游标下移
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

//测试案例 约瑟夫问题的求解
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
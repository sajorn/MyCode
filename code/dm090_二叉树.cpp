#include <iostream>
#include <stack>
using namespace std;

//��������
typedef struct stBiTree
{
	int data;
	stBiTree *lchild, *rchild;
}BitNode, *BiTree;

//�������
void PriOrder(BitNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->data << " ";
	//����������
	PriOrder(root->lchild);
	//����������
	PriOrder(root->rchild);
}

//�������
void MidOrder(BitNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	//����������
	MidOrder(root->lchild);

	cout << root->data << " ";

	//����������
	MidOrder(root->rchild);
}

//�������
void LastOrder(BitNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	//����������
	LastOrder(root->lchild);
	//����������
	LastOrder(root->rchild);

	cout << root->data << " ";
}

//���������Ҷ�ӽڵ�
void CountLeaves(BitNode *root, int *sum)
{
	if (root == nullptr)
	{
		return;
	}

	if (!root->lchild && !root->rchild)
	{
		(*sum)++;
	}

	if (root->lchild)
	{
		CountLeaves(root->lchild, sum);
	}
	if (root->rchild)
	{
		CountLeaves(root->rchild, sum);
	}

}

//��������ĸ߶�
void CountHeight(BitNode *root, int *sum)
{
	if (root == nullptr)
	{
		return;
	}
	int lChildHeight = 0;
	int rChildHeight = 0;

	if (root->lchild)
	{
		CountHeight(root->lchild, sum);
		lChildHeight = (*sum);
	}
	if (root->rchild)
	{
		CountHeight(root->rchild, sum);
		rChildHeight = (*sum);
	}

	(*sum) = 1 + (lChildHeight > rChildHeight ? lChildHeight : rChildHeight);
}

//copy��
BitNode* CopyBiTree(BitNode *tree)
{
	BitNode* rootNode = nullptr;
	BitNode* leftNode = nullptr;
	BitNode* rightNode = nullptr;

	if (tree == nullptr)
	{
		return nullptr;
	}
	//����������
	if (tree->lchild)
	{
		leftNode = CopyBiTree(tree->lchild);
	}
	else
	{
		leftNode = nullptr;
	}

	//����������
	if (tree->rchild)
	{
		rightNode = CopyBiTree(tree->rchild);
	}
	else
	{
		rightNode = nullptr;
	}

	//Ϊ�ڵ����ռ�
	rootNode = new BitNode;
	rootNode->lchild = leftNode;
	rootNode->rchild = rightNode;
	rootNode->data = tree->data;

	return rootNode;
}

//�ǵݹ�ʵ���������
// ����1����������·�����
// �����������������ý����ջ��
// ������û�������������ʸý�㣻
// ����3��·���������
// �����������������ظ�����1��
// ������û������������������ϣ������ˣ���ջ��Ԫ�س�ջ������ջ��Ԫ�أ����������������ظ�����1
// ���ջΪ�գ���ʾ����������

//�ҳ������������
BitNode* GoLeft(BitNode* t, stack<BitNode*>& s)
{
	if (t == nullptr)
	{
		return nullptr;
	}

	while (t->lchild)
	{
		s.push(t);
		t = t->lchild;
	}

	return t;
}

//�������
void MidOrder2(BitNode* root)
{
	stack<BitNode*> s;
	if (root == nullptr)
	{
		return;
	}

	root = GoLeft(root, s); //�ҵ������������

	while (root)
	{
		cout << root->data << " ";
		if (root->rchild) //����ý���������������ظ��ҳ�������������ڵ�
		{
			root = GoLeft(root->rchild, s);
		}
		else if (!s.empty()) 
		{
			root = s.top();
			s.pop();
		}
		else
		{
			root = nullptr;
		}
	}
}

//#��������
BitNode* CreateBitTree()
{
	BitNode* node = nullptr;
	BitNode* lchild = nullptr;
	BitNode* rchild = nullptr;

	char ch;
	cin >> ch;
	if (ch == '#')
	{
		return nullptr;
	}
	else
	{
		node = new BitNode;
		node->data = ch;
		lchild = CreateBitTree();
		node->lchild = lchild;
		rchild = CreateBitTree();
		node->rchild = rchild;
	}
	return node; 
}

//�ͷ���
int FreeTree(BitNode* tree)
{
	if (tree->lchild)
	{
		FreeTree(tree->lchild);
		tree->lchild = nullptr;
	}
	if (tree->rchild)
	{
		FreeTree(tree->rchild);
		tree->rchild = nullptr;
	}
	if (tree)
	{
		delete tree;
		tree = nullptr;
	}

	return 0;
}

int main()
{
	BitNode t1, t2, t3, t4, t5;
	memset(&t1, 0, sizeof(BitNode));
	memset(&t2, 0, sizeof(BitNode));
	memset(&t3, 0, sizeof(BitNode));
	memset(&t4, 0, sizeof(BitNode));
	memset(&t5, 0, sizeof(BitNode));
	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.lchild = &t2;
	t1.rchild = &t3;
	t2.lchild = &t4;
	t3.lchild = &t5;

	BitNode* tree = CreateBitTree();
	cout << "�������: ";
	MidOrder(tree);
	cout << endl;

	cout << "ǰ������� ";
	PriOrder(&t1);
	cout << endl;
	cout << "��������� ";
	MidOrder(&t1);
	cout << endl;
	cout << "�������2�� ";
	MidOrder2(&t1);
	cout << endl;
	cout << "��������� ";
	LastOrder(&t1);
	cout << endl;

	int leaves = 0;
	CountLeaves(&t1, &leaves);
	cout << "Leaves: " << leaves << endl;

	int depth = 0;
	CountHeight(&t1, &depth);
	cout << "Depth: " << depth << endl;

	BitNode* newTree;
	newTree = CopyBiTree(&t1);

	cout << "ǰ�����: ";
	PriOrder(newTree);
	cout << endl;
	cout << "�������: ";
	MidOrder(newTree);
	cout << endl;
	cout << "�������: ";
	LastOrder(newTree);
	cout << endl;
	return 0;
}
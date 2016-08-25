#include <iostream>
#include <stack>
using namespace std;

//二叉链表
typedef struct stBiTree
{
	int data;
	stBiTree *lchild, *rchild;
}BitNode, *BiTree;

//先序遍历
void PriOrder(BitNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->data << " ";
	//遍历左子树
	PriOrder(root->lchild);
	//遍历右子树
	PriOrder(root->rchild);
}

//中序遍历
void MidOrder(BitNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	//遍历左子树
	MidOrder(root->lchild);

	cout << root->data << " ";

	//遍历右子树
	MidOrder(root->rchild);
}

//后序遍历
void LastOrder(BitNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	//遍历左子树
	LastOrder(root->lchild);
	//遍历右子树
	LastOrder(root->rchild);

	cout << root->data << " ";
}

//求二叉树的叶子节点
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

//求二叉树的高度
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

//copy树
BitNode* CopyBiTree(BitNode *tree)
{
	BitNode* rootNode = nullptr;
	BitNode* leftNode = nullptr;
	BitNode* rightNode = nullptr;

	if (tree == nullptr)
	{
		return nullptr;
	}
	//拷贝左子树
	if (tree->lchild)
	{
		leftNode = CopyBiTree(tree->lchild);
	}
	else
	{
		leftNode = nullptr;
	}

	//拷贝右子树
	if (tree->rchild)
	{
		rightNode = CopyBiTree(tree->rchild);
	}
	else
	{
		rightNode = nullptr;
	}

	//为节点分配空间
	rootNode = new BitNode;
	rootNode->lchild = leftNode;
	rootNode->rchild = rightNode;
	rootNode->data = tree->data;

	return rootNode;
}

//非递归实现中序遍历
// 步骤1：结点的所有路径情况
// 如果结点有左子树，该结点入栈；
// 如果结点没有左子树，访问该结点；
// 分析3：路径所有情况
// 如果结点有右子树，重复步骤1；
// 如果结点没有右子树（结点访问完毕），回退，让栈顶元素出栈，访问栈顶元素，并访问右子树，重复步骤1
// 如果栈为空，表示遍历结束。

//找出左子树的起点
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

//中序遍历
void MidOrder2(BitNode* root)
{
	stack<BitNode*> s;
	if (root == nullptr)
	{
		return;
	}

	root = GoLeft(root, s); //找到左子树的起点

	while (root)
	{
		cout << root->data << " ";
		if (root->rchild) //如果该结点有右子树，则重复找出该右子树的左节点
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

//#法创建树
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

//释放树
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
	cout << "中序遍历: ";
	MidOrder(tree);
	cout << endl;

	cout << "前序遍历： ";
	PriOrder(&t1);
	cout << endl;
	cout << "中序遍历： ";
	MidOrder(&t1);
	cout << endl;
	cout << "中序遍历2： ";
	MidOrder2(&t1);
	cout << endl;
	cout << "后序遍历： ";
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

	cout << "前序遍历: ";
	PriOrder(newTree);
	cout << endl;
	cout << "中序遍历: ";
	MidOrder(newTree);
	cout << endl;
	cout << "后序遍历: ";
	LastOrder(newTree);
	cout << endl;
	return 0;
}
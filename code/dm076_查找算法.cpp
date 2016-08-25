#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std; 

int PrintElem(int n)
{
	cout << n << " ";
	return n;
}

bool IsGreat(int n)
{
	return n > 2;
}

int main()
{
	vector<int> v1;
	int nTemp;
	for (unsigned i = 0; i < 10; ++i)
	{
		nTemp = rand() % 5;
		v1.push_back(nTemp);
	}
	transform(v1.begin(), v1.end(), v1.begin(), PrintElem);
	//1 2 4 0 4 4 3 3 2 4
	cout << endl;
	//���ҵ�һ���ظ�Ԫ�صĵ�����λ��, ��ǰһ���ͺ�һ��Ԫ����ͬ
	vector<int>::iterator it1 = adjacent_find(v1.begin(), v1.end());
	if (it1 == v1.end())
	{
		cout << "û���ظ���Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ���һ���ظ�������: " << *it1 << endl;
	}

	//�õ���������λ��
	int nIndex = distance(v1.begin(), it1);
	cout << "index: " << nIndex << endl;

	cout << "----binary_search���ֲ���----" << endl;
	//���ֲ��ң�����bool����
	bool IsFind = binary_search(v1.begin(), v1.end(), 4);
	if (IsFind)
	{
		cout << "�ҵ���Ԫ��" << endl;
	}
	else
	{
		cout << "�Ҳ�����Ԫ��" << endl;
	}

	cout << "---count�÷�---" << endl;
	//����ĳԪ�س��ֵĴ���
	int num = count(v1.begin(), v1.end(), 4);
	cout << "���ֵĴ���: " << num << endl;

	cout << "---count_if�÷�---" << endl;
	//�ҵ�����ĳ������Ԫ�صĴ���
	num = count_if(v1.begin(), v1.end(), IsGreat);
	cout << "���ֵĴ���: " << num << endl;

	cout << "---find���÷�---" << endl;
	//����ĳԪ��
	vector<int>::iterator it = find(v1.begin(), v1.end(), 0);
	if (it == v1.end())
	{
		cout << "û���ҵ���Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ���Ԫ��: " << *it << endl;
	}

	cout << "---find_if���÷�---" << endl;
	//�����Ƿ�������������Ԫ��
	it = find_if(v1.begin(), v1.end(), IsGreat);
	if (it == v1.end())
	{
		cout << "û���ҵ����ϵ�Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ����ϵ�Ԫ��: " << *it << endl;
	}

	return 0;
}
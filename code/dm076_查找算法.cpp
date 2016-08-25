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
	//查找第一个重复元素的迭代器位置, 即前一个和后一个元素相同
	vector<int>::iterator it1 = adjacent_find(v1.begin(), v1.end());
	if (it1 == v1.end())
	{
		cout << "没有重复的元素" << endl;
	}
	else
	{
		cout << "找到第一个重复的数字: " << *it1 << endl;
	}

	//得到迭代器的位置
	int nIndex = distance(v1.begin(), it1);
	cout << "index: " << nIndex << endl;

	cout << "----binary_search二分查找----" << endl;
	//二分查找，返回bool类型
	bool IsFind = binary_search(v1.begin(), v1.end(), 4);
	if (IsFind)
	{
		cout << "找到该元素" << endl;
	}
	else
	{
		cout << "找不到该元素" << endl;
	}

	cout << "---count用法---" << endl;
	//查找某元素出现的次数
	int num = count(v1.begin(), v1.end(), 4);
	cout << "出现的次数: " << num << endl;

	cout << "---count_if用法---" << endl;
	//找到满足某条件的元素的次数
	num = count_if(v1.begin(), v1.end(), IsGreat);
	cout << "出现的次数: " << num << endl;

	cout << "---find的用法---" << endl;
	//查找某元素
	vector<int>::iterator it = find(v1.begin(), v1.end(), 0);
	if (it == v1.end())
	{
		cout << "没有找到该元素" << endl;
	}
	else
	{
		cout << "找到该元素: " << *it << endl;
	}

	cout << "---find_if的用法---" << endl;
	//查找是否有满足条件的元素
	it = find_if(v1.begin(), v1.end(), IsGreat);
	if (it == v1.end())
	{
		cout << "没有找到符合的元素" << endl;
	}
	else
	{
		cout << "找到符合的元素: " << *it << endl;
	}

	return 0;
}
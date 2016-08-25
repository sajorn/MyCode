/*
在一个由自然数1-1000中某些数字所组成的数组中，每个数字可能出现零次或者多次。
设计一个算法，找出出现次数最多的数字。

*/

#include <iostream>
#include <map>
using namespace std;

#define MAX_LEN 50

int SearchMax(int* a, int nLen)
{
	int tArr[20] = { 0 };
	for (int i = 0; i < nLen; ++i)
	{
		int tmp = a[i] - 1;
		tArr[tmp]++;
	}
	int nMax = 0;
	for (int i = 0; i < 20; ++i)
	{
		if (nMax < tArr[i])
		{
			nMax = tArr[i];
		}
	}
	for (int i = 0; i < 20; ++i)
	{
		if (nMax == tArr[i])
		{
			cout << "MaxNum: " << i + 1 << "\t Count: " << nMax << endl; 
		}
	}
	return 0;
}

int main()
{
	int arr[MAX_LEN] = { 0 };
	for (unsigned i = 0; i < MAX_LEN; ++i)
	{
		arr[i] = rand() % 20 + 1;
	}

	for (unsigned i = 0; i < MAX_LEN; ++i)
	{
		cout << arr[i] << endl;
	}

	SearchMax(arr, MAX_LEN);

	//方法2
	cout << "----方法2----" << endl;
	map<int, int> m;
	for (int i = 0; i < MAX_LEN; ++i)
	{
		pair<map<int, int>::iterator, bool> pairIt = m.insert(pair<int, int>(arr[i], 1));
		if (pairIt.second != true)
		{
			m[arr[i]]++;
		}
	}
	


	int nMax = 0; //出现最大的频率
	int n = 0; //下标
	int data = 0; //a[i]
	for (unsigned i = 0; i < m.size(); ++i)
	{
		if (nMax < m[arr[i]])
		{
			n = i;
			data = arr[i];
			nMax = m[arr[i]];
		}
	}

	for (unsigned i = 0; i < m.size(); ++i)
	{
		if (nMax == m[arr[i]])
		{
			cout << "a[" << i << "] = " << nMax << endl;
		}
	}
	
	return 0;
}
/*
��һ������Ȼ��1-1000��ĳЩ��������ɵ������У�ÿ�����ֿ��ܳ�����λ��߶�Ρ�
���һ���㷨���ҳ����ִ����������֡�

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

	//����2
	cout << "----����2----" << endl;
	map<int, int> m;
	for (int i = 0; i < MAX_LEN; ++i)
	{
		pair<map<int, int>::iterator, bool> pairIt = m.insert(pair<int, int>(arr[i], 1));
		if (pairIt.second != true)
		{
			m[arr[i]]++;
		}
	}
	


	int nMax = 0; //��������Ƶ��
	int n = 0; //�±�
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
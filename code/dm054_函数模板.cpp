/*
	函数模板实现int char double类型的交换函数swap
	函数模板实现数组排序
*/

#include <iostream>
using namespace std;

//交换模板
template <typename T>
void Swap(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

//数组排序模板
template <typename T1, typename T2>
int Sort(T1* arr, T2 len)
{
	T2 i, j;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = i + 1; j < len; ++j)
		{
			if (arr[i] > arr[j])
			{
				T1 tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return 0;
}

//数组打印模板
template <typename T>
int Print(T* arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}

int main()
{
	//交换测试案例
	{
		int a = 3, b = 4;
		double c = 3.0, d = 5.0;
		char e = 'e', f = 'f';
		Swap<int>(a, b);
		Swap<double>(c, d);
		Swap<char>(e, f);
		cout << a << ", " << b << endl;
		cout << c << ", " << d << endl;
		cout << e << ", " << f << endl;
	}
	//数组测试案例
	{
		int nArray[] = { 12, 34, 52, 12, 34, 56, 23, 12, 63, 34, 77, 89, 45, 73 };
		int nLen = sizeof(nArray) / sizeof(int);
		Sort<int, int>(nArray, nLen);
		char chArray[] = "nlgadnfaoroqnlwe";
		int chLen = strlen(chArray);
		Sort<char, int>(chArray, chLen);

		Print<int>(nArray, nLen);
		Print<char>(chArray, chLen);
	}
	return 0;
}
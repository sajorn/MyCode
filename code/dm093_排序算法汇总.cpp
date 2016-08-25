#include <iostream>
using namespace std;

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//选择法排序
void SelectSort(int* arr, int size)
{
	int mIndex; //最小值下标
	for (int i = 0; i < size - 1; ++i)
	{
		mIndex = i;
		for (int j = i; j < size; ++j)
		{
			if (arr[j] < arr[mIndex]) //找出最小值的下标
			{
				mIndex = j;
			}
		}
		if (arr[i] > arr[mIndex])
		{
			int tmp = arr[i];
			arr[i] = arr[mIndex];
			arr[mIndex] = tmp;
		}
	}

	PrintArray(arr, size);
}

//插入法排序
void InsertSort(int* arr, int size)
{
	int tIndex; //待插入元素的下标
	for (int i = 1; i < size; ++i)
	{
		tIndex = i;
		int tmp = arr[tIndex]; //保存当前的值

		for (int j = i - 1; (j >= 0) && (arr[j] > tmp); --j)
		{
			arr[j + 1] = arr[j];
			tIndex = j; //待插入元素的下标
		}
		arr[tIndex] = tmp;
	}

	PrintArray(arr, size);
}

//冒泡法排序
void BubbleSort(int* arr, int size)
{
	bool isSort = false; //默认表示未排好序，冒泡的改进算法
	for (int i = 0; i < size - 1 && !isSort; ++i)
	{
		isSort = true;
		for (int j = i; j < size - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				isSort = false;
			}
		}
	}

	PrintArray(arr, size);
}

//希尔排序 不稳定
void ShellSort(int* arr, int size)
{
	int gap = size; 
	do 
	{
		gap = gap / 3 + 1; //分组的个数

		for (int i = gap; i < size; i += gap)
		{
			for (int j = i - gap; j >= 0; j -= gap)
			{
				if (arr[j] > arr[j + gap])
				{
					int tmp = arr[j];
					arr[j] = arr[j + gap];
					arr[j + gap] = tmp;
				}
			}
		}
	} while (gap > 1);

	PrintArray(arr, size);
}

//快速排序 不稳定
int FSortPosition(int* arr, int low, int high)
{
	int pv = arr[low];

	while (low < high)
	{
		while ((low < high) && (arr[high] >= pv))
		{
			high--;
		}
		if (arr[high] < arr[low])
		{
			int tmp = arr[high];
			arr[high] = arr[low];
			arr[low] = tmp;
		}
		while ((low < high) && (arr[low] <= pv))
		{
			low++;
		}
		if (arr[high] < arr[low])
		{
			int tmp = arr[high];
			arr[high] = arr[low];
			arr[low] = tmp;
		}
	}

	return low;
}

void FSort(int* arr, int low, int high)
{
	if (low < high)
	{
		//选一个值，把数据分别放在该值的左右，并把它的位置返回出去
		int pv = FSortPosition(arr, low, high);

		//对pv的左边进行排序
		FSort(arr, low, pv - 1);

		//对pv的右边进行排序
		FSort(arr, pv + 1, high);
	}
}

void FastSort(int* arr, int size)
{
	FSort(arr, 0, size - 1);
	PrintArray(arr, size);
}

//归并排序 稳定 但是会牺牲空间

void Merge(int* src, int* des, int low, int mid, int high)
{
	int i = low; //前半部分的序列
	int j = mid + 1; //后半部分的序列
	int k = low; //用来存放归并后的序列

	while ((i <= mid) && (j <= high))
	{
		if (src[i] < src[j]) //谁小就将谁放进归并序列里
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid) //将前半部分剩下的放进去
	{
		des[k++] = src[i++];
	}
	while (j <= high) //将后半部分剩下的放进去
	{
		des[k++] = src[j++];
	}
}

void MSort(int* src, int* des, int low, int high, int max)
{
	if (low == high) //只有一个元素的时候，不需要归并排序
	{
		des[low] = src[low];
	}
	else //否则的话，进行二路归并排序
	{
		int mid = (low + high) / 2;
		int* tSpace = new int[max];
		//递归进行两路划分
		if (tSpace != nullptr)
		{
			MSort(src, tSpace, low, mid, max);
			MSort(src, tSpace, mid + 1, high, max);
			Merge(tSpace, des, low, mid, high);
		}
		delete[] tSpace;
	}
}

void MergeSort(int* arr, int size)
{
	MSort(arr, arr, 0, size - 1, size);
	PrintArray(arr, size);
}


int main()
{
	int arr[] = { 1, 4, 6, 2, 3, 7, 9, 8, 5 };
	int size = sizeof(arr) / sizeof(int);

	//SelectSort(arr, size);
	//InsertSort(arr, size);
	//BubbleSort(arr, size);
	//ShellSort(arr, size);
	//FastSort(arr, size);
	MergeSort(arr, size);
	return 0;
}
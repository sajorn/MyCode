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

//ѡ������
void SelectSort(int* arr, int size)
{
	int mIndex; //��Сֵ�±�
	for (int i = 0; i < size - 1; ++i)
	{
		mIndex = i;
		for (int j = i; j < size; ++j)
		{
			if (arr[j] < arr[mIndex]) //�ҳ���Сֵ���±�
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

//���뷨����
void InsertSort(int* arr, int size)
{
	int tIndex; //������Ԫ�ص��±�
	for (int i = 1; i < size; ++i)
	{
		tIndex = i;
		int tmp = arr[tIndex]; //���浱ǰ��ֵ

		for (int j = i - 1; (j >= 0) && (arr[j] > tmp); --j)
		{
			arr[j + 1] = arr[j];
			tIndex = j; //������Ԫ�ص��±�
		}
		arr[tIndex] = tmp;
	}

	PrintArray(arr, size);
}

//ð�ݷ�����
void BubbleSort(int* arr, int size)
{
	bool isSort = false; //Ĭ�ϱ�ʾδ�ź���ð�ݵĸĽ��㷨
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

//ϣ������ ���ȶ�
void ShellSort(int* arr, int size)
{
	int gap = size; 
	do 
	{
		gap = gap / 3 + 1; //����ĸ���

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

//�������� ���ȶ�
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
		//ѡһ��ֵ�������ݷֱ���ڸ�ֵ�����ң���������λ�÷��س�ȥ
		int pv = FSortPosition(arr, low, high);

		//��pv����߽�������
		FSort(arr, low, pv - 1);

		//��pv���ұ߽�������
		FSort(arr, pv + 1, high);
	}
}

void FastSort(int* arr, int size)
{
	FSort(arr, 0, size - 1);
	PrintArray(arr, size);
}

//�鲢���� �ȶ� ���ǻ������ռ�

void Merge(int* src, int* des, int low, int mid, int high)
{
	int i = low; //ǰ�벿�ֵ�����
	int j = mid + 1; //��벿�ֵ�����
	int k = low; //������Ź鲢�������

	while ((i <= mid) && (j <= high))
	{
		if (src[i] < src[j]) //˭С�ͽ�˭�Ž��鲢������
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}

	while (i <= mid) //��ǰ�벿��ʣ�µķŽ�ȥ
	{
		des[k++] = src[i++];
	}
	while (j <= high) //����벿��ʣ�µķŽ�ȥ
	{
		des[k++] = src[j++];
	}
}

void MSort(int* src, int* des, int low, int high, int max)
{
	if (low == high) //ֻ��һ��Ԫ�ص�ʱ�򣬲���Ҫ�鲢����
	{
		des[low] = src[low];
	}
	else //����Ļ������ж�·�鲢����
	{
		int mid = (low + high) / 2;
		int* tSpace = new int[max];
		//�ݹ������·����
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
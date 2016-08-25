#include <iostream>

using namespace std;

class Array{
public:
	Array(int length)
	{
		length_ = length;
		pArray_ = new int[length_];
	}
	Array(const Array& obj)
	{
		length_ = obj.length_;
		pArray_ = new int[length_];
		
		for (int i = 0; i < length_; ++i)
		{
			pArray_[i] = obj.pArray_[i];
		}
	}
	int length()
	{
		return length_;
	}
	void setData(int index, int value)
	{
		if (index >= length_)
		{
			cout << "数组越界" << endl;
			return;
		}
		pArray_[index] = value;
	}
	int getData(int index)
	{
		return pArray_[index];
	}
	~Array()
	{
		if (pArray_)
		{
			delete[] pArray_;
		}
	}

private:
	int length_; //数组的下标
	int* pArray_; //指向数组首元素地址
};

int main()
{
	Array a1(10);

	for (int i = 0; i < a1.length(); i++)
	{
		a1.setData(i, i);
	}

	for (int i = 0; i < a1.length(); i++)
	{
		printf("array %d: %d\n", i, a1.getData(i));
	}

	Array a2 = a1;

	for (int i = 0; i < a2.length(); i++)
	{
		printf("array %d: %d\n", i, a2.getData(i));
	}

	return 0;
}
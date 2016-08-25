#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int>& v)
{
	for (unsigned i = 0; i < v.size(); ++i)
	{
		cout << v.at(i) << " ";
	}
	cout << "Len: " << v.size() << endl;
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	cout << "length: " << v1.size() << endl; //求长度
	while (v1.size())
	{
		cout << v1.back() << endl;  //获取尾部的元素
		v1.pop_back(); //删除尾部元素
	}
	cout << "length: " << v1.size() << endl;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(6);
	//拷贝
	vector<int> v2 = v1;
	PrintVector(v2);
	vector<int> v3(v1.begin(), v1.end() - 1); //区间拷贝
	PrintVector(v3);

	vector<int> v4(10); //提前分配了10个int内存空间
	v4.push_back(100);
	v4.push_back(200);
	PrintVector(v4); //从尾部添加了两个之后一共占12个int大小

	//迭代器正向遍历和逆向遍历
	vector<int> v5(10);
	for (unsigned i = 0; i < v5.size(); ++i)
	{
		v5.at(i) = i + 1;
	}

	for (vector<int>::iterator it = v5.begin(); it != v5.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for (vector<int>::reverse_iterator rit = v5.rbegin(); rit != v5.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;

	//删除和插入
	v5.erase(v5.begin(), v5.begin() + 3);
	PrintVector(v5);
	v5.erase(v5.begin());
	PrintVector(v5);

	//删除特定元素
	for (vector<int>::iterator it = v5.begin(); it != v5.end(); ++it)
	{
		if (*it == 8)
		{
			it = v5.erase(it); //删除之后要将it的地址返回给it,it会自动后移
		}
	}
	PrintVector(v5);

	//头插和尾插
	v5.insert(v5.begin(), 100);
	v5.insert(v5.end(), 200);
	PrintVector(v5);
	return 0;
}
#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
class PrintElem
{
public:
	PrintElem()
	{
		num = 0;
	}
	void operator()(T &t)
	{
		num++;
		cout << t << " ";
	}
	void PrintNum()
	{
		cout << "Num: " << num << endl;
	}
private:
	int num; 
};

int Increase(int n)
{
	return n + 100;
}

int main()
{
	vector<int> v1;
	for (unsigned i = 0; i < 5; ++i)
	{
		v1.push_back(i + 1);
	}

	//for_each遍历容器
	PrintElem<int> p1;
	p1 = for_each(v1.begin(), v1.end(), PrintElem<int>());
	p1.PrintNum();
	cout << endl;

	//transform基本用法
	//1.回调函数 需要有返回值
	transform(v1.begin(), v1.end(), v1.begin(), Increase);
	for_each(v1.begin(), v1.end(), PrintElem<int>());
	cout << endl;

	//2.预定义函数 变负数
	transform(v1.begin(), v1.end(), v1.begin(), negate<int>());
	for_each(v1.begin(), v1.end(), PrintElem<int>());
	cout << endl;

	//3.函数适配器
	transform(v1.begin(), v1.end(), v1.begin(), bind2nd(multiplies<int>(), 2));
	for_each(v1.begin(), v1.end(), PrintElem<int>());
	cout << endl;

	//4.输出到屏幕
	//ostream_iterator是输出迭代器，第二个参数是分隔符
	transform(v1.begin(), v1.end(), ostream_iterator<int>(cout, ", "), negate<int>());
	cout << endl;

	return 0;
}
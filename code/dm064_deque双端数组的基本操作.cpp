#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void PrintDeque(deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(-1);
	d.push_front(-2);
	d.push_front(-3);
	PrintDeque(d);

	d.pop_back();
	d.pop_front();
	PrintDeque(d);

	//查找特定的值
	deque<int>::iterator it = find(d.begin(), d.end(), 1);
	if (it != d.end())
	{
		cout << "下标：" << distance(d.begin(), it) << endl;
	}
	else
	{
		cout << "没有找到这个数字" << endl;
	}

	return 0;
}
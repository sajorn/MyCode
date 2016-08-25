#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<double> q;
	q.push(1.1); //入队
	q.push(2.2);
	q.push(3.3);
	cout << "Len: " << q.size() << endl; //求长度

	while (!q.empty())
	{
		cout << q.front() << endl; //求头部元素
		q.pop(); //删除头部元素
	}
	return 0;
}
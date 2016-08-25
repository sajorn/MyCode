#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> >q1; //最小值优先级
	priority_queue<int> q2; //最大值优先级（默认） //想当于less<int>
	q1.push(17);
	q1.push(18);
	q1.push(16);
	q2.push(17);
	q2.push(18);
	q2.push(16);
	while (q1.size() > 0)
	{
		cout << q1.top() << " ";
		q1.pop();
	}
	cout << endl;

	while (q2.size() > 0)
	{
		cout << q2.top() << " ";
		q2.pop();
	}
	cout << endl;
	return 0;
}
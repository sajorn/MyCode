#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<double> q;
	q.push(1.1); //���
	q.push(2.2);
	q.push(3.3);
	cout << "Len: " << q.size() << endl; //�󳤶�

	while (!q.empty())
	{
		cout << q.front() << endl; //��ͷ��Ԫ��
		q.pop(); //ɾ��ͷ��Ԫ��
	}
	return 0;
}
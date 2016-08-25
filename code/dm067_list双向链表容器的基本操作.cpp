#include <iostream>
#include <list>
using namespace std;

void PrintList(list<int>& l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "Len: " << l.size() << endl;
	cout << endl;
}

int main()
{
	list<int> l;
	for (int i = 0; i < 10; ++i)
	{
		l.push_back(i + 1);
	}
	PrintList(l);
	//����
	list<int>::iterator it = l.begin();
	it++;
	it++;
	//������it+3;
	it++;
	l.insert(it, 100);
	l.insert(l.begin(), 100);
	PrintList(l);
	l.remove(100); //ɾ��ͬһ��Ԫ��
	PrintList(l);
	l.erase(l.begin(), it);
	PrintList(l);
	it++;
	l.erase(it);
	PrintList(l);
	return 0;
}
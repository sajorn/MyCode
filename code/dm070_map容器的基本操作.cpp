#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<int, string> m; //map<key, value>
	//��������ַ�ʽ
	m.insert(pair<int, string>(1, "MyTeam1"));

	m.insert(make_pair(2, "MyTeam2"));

	m.insert(map<int, string>::value_type(3, "MyTeam3"));

	m[4] = "MyTeam4";


	pair<map<int, string>::iterator, bool> p = m.insert(make_pair(2, "MyTeam5"));
	if (p.second != true)
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "����ɹ�" << endl;
		cout << p.first->first << "\t" << p.first->second << endl;
	}

	//����
	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}

	//ɾ��
	for (map<int, string>::iterator it = m.begin(); it != m.end();)
	{
		it = m.erase(it);
	}

	//����
	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(make_pair(2, 19));
	m1.insert(map<int, int>::value_type(3, 20));
	m1[4] = 42;

	map<int, int>::iterator it = m1.find(2);
	if (it == m1.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << it->first << "\t" << it->second << endl;
	}

	cout << "----" << endl;

	pair<map<int, int>::iterator, map<int, int>::iterator> p1 = m1.equal_range(4);
	if (p1.first == m1.end())
	{
		cout << "�Ҳ���>=4" << endl;
	}
	else
	{
		cout << p1.first->first << "\t" << p1.first->second << endl;
	}

	if (p1.second == m1.end())
	{
		cout << "�Ҳ���>4" << endl;
	}
	else
	{
		cout << p1.second->first << "\t" << p1.second->second << endl;
	}

	return 0;
}
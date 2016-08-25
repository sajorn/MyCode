#include <iostream>
#include <functional>
#include <set>
#pragma warning(disable:4996)
using namespace std;

class cStudent
{
public:
	cStudent(char* name, int age)
	{
		strcpy(m_name, name);
		m_age = age;
	}
public:
	int m_age;
	char m_name[8];
};

//仿函数
struct stFunc
{
	bool operator() (const cStudent& s1, const cStudent& s2)
	{
		if (s1.m_age > s2.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void PrintSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "Len: " << s.size() << endl;
	cout << endl;
}

int main()
{
	set<int> s1;
	for (int i = 0; i < 10; ++i)
	{
		int tmp = rand();
		s1.insert(tmp);
	}
	s1.insert(100);
	s1.insert(100);
	PrintSet(s1);
	s1.erase(--s1.end());
	PrintSet(s1);
	
	set<int, greater<int>> s2;
	for (int i = 0; i < 10; ++i)
	{
		int tmp = rand();
		s2.insert(tmp);
	}
	for (set<int>::iterator it = s2.begin(); it != s2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << "Len: " << s2.size() << endl;
	cout << endl;

	//自定义数据类型的排序
	cStudent cs1("s1", 11);
	cStudent cs2("s2", 12);
	cStudent cs3("s3", 10);
	cStudent cs4("s4", 10);

	set<cStudent, stFunc> set1;
	set1.insert(cs1);
	set1.insert(cs2);
	set1.insert(cs3);
	set1.insert(cs4);
	for (set<cStudent, stFunc>::iterator it = set1.begin(); it != set1.end(); ++it)
	{
		cout << it->m_age << " " << it->m_name << endl;
	}
	
	set<int> s3;
	for (unsigned i = 0; i < 10; ++i)
	{
		s3.insert(i);
	}
	PrintSet(s3);
	set<int>::iterator it1 = find(s3.begin(), s3.end(), 1);
	cout << "it1: " << *it1 << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

void PrintElem(int& n)
{
	cout << n << " ";
}

class cTeacher
{
public:
	cTeacher(const string& name, const unsigned& age)
	{
		m_name = name;
		m_age = age;
	}

	friend ostream& operator<<(ostream& os, cTeacher& refTea)
	{
		os << "Age: " << refTea.m_age << "\t" << "Name: " << refTea.m_name;
		return os;
	}
	string m_name;
	unsigned m_age;
};

bool CompareAge(const cTeacher& t1, const cTeacher& t2)
{
	return t1.m_age > t2.m_age;
}

int main()
{
	vector<int> v1, v2;
	for (unsigned i = 0; i < 5; ++i)
	{
		v1.push_back(i * 2 - 1);
	}
	for_each(v1.begin(), v1.end(), PrintElem);
	cout << endl;

	for (unsigned i = 0; i < 10; ++i)
	{
		v2.push_back(i * 2);
	}
	for_each(v2.begin(), v2.end(), PrintElem);
	cout << endl;

	vector<int> v3;
	v3.resize(v1.size() + v2.size());

	//合并两个序列，放在另一个序列中
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), v3.end(), PrintElem);
	cout << endl;

	//随机排序
	vector<int> v4;
	for (unsigned i = 0; i < 10; ++i)
	{
		v4.push_back(i + 1);
	}
	random_shuffle(v4.begin(), v4.end());
	for_each(v4.begin(), v4.end(), PrintElem);
	cout << endl;

	//倒序排序
	vector<int> v5;
	for (unsigned i = 0; i < 10; ++i)
	{
		v5.push_back(i + 1);
	}
	reverse(v5.begin(), v5.end());
	for_each(v5.begin(), v5.end(), PrintElem);
	cout << endl;

	//sort排序
	cTeacher t1("Mike", 31);
	cTeacher t2("John", 32);
	cTeacher t3("Tom", 33);
	cTeacher t4("Jack", 34);
	vector<cTeacher> v6;
	v6.push_back(t3);
	v6.push_back(t4);
	v6.push_back(t1);
	v6.push_back(t2);
	sort(v6.begin(), v6.end(), CompareAge);
	for (vector<cTeacher>::iterator it = v6.begin(); it != v6.end(); ++it)
	{
		cout << *it << endl;
	}
	return 0;
}
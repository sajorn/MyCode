#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class cTeacher
{
public:
	int m_age;
};

int main()
{
	vector<int> v1; //容器
	v1.push_back(1); //将值拷入容器中（浅拷贝）
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	
	//迭代器
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << "num: " << *it << endl;
	}

	//算法
	int nCount = count(v1.begin(), v1.end(), 2); //统计元素出现的次数
	cout << nCount << endl;

	cout << "----华丽分割线----" << endl;
	cTeacher t1, t2, t3;
	t1.m_age = 1;
	t2.m_age = 2;
	t3.m_age = 3;
	cTeacher* p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;
	vector<cTeacher*> v2;
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);

	for (vector<cTeacher*>::iterator it = v2.begin(); it != v2.end(); ++it)
	{
		cout << "age: " << (*it)->m_age << endl;
	}
	return 0;
}
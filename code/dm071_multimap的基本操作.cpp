/*
	公司有销售部 sale （员工2名）、技术研发部 development （1人）、财务部 Financial （2人）
	人员信息有：姓名，年龄，电话、工资等组成
	通过 multimap进行 信息的插入、保存、显示
	分部门显示员工信息
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

class cPerson
{
public:
	string m_name;
	int m_age;
	string m_tel;
	double m_sal;
};

int main()
{
	cPerson p[5];
	for (int i = 0; i < 5; ++i)
	{
		p[i].m_name = "liu";
		p[i].m_age = 31 + i;
	}

	multimap<string, cPerson> m;
	m.insert(pair<string, cPerson>("sale", p[0]));
	m.insert(make_pair("sale", p[1]));
	m.insert(multimap<string, cPerson>::value_type("development", p[2]));
	m.insert(multimap<string, cPerson>::value_type("Financial", p[3]));
	m.insert(pair<string, cPerson>("Financial", p[4]));


	multimap<string, cPerson>::iterator it1 = m.find("sale");


	for (multimap<string, cPerson>::iterator it = m.begin(); it != m.end(); ++it)
	{
		if (it == it1)
		{
			cout << it->first << "\t" << it->second.m_name << endl;
		}
	}

	return 0;
}

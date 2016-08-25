#include <iostream>
#include <stack>
using namespace std;

class cPerson
{
public:
	int m_age;
	void PrintAge()
	{
		cout << "m_age = " << m_age << endl;
	}
};

int main()
{
	cPerson p1, p2, p3;
	p1.m_age = 31;
	p2.m_age = 32;
	p3.m_age = 33;

	stack<cPerson*> s;
	s.push(&p1); //��ջ
	s.push(&p2);
	s.push(&p3);
	while (!s.empty()) //ջ��Ϊ��
	{
		cPerson* tmp = s.top(); //��ȡջ��Ԫ��
		tmp->PrintAge();
		s.pop(); //ɾ��ջ��Ԫ��
	}

	return 0;
}
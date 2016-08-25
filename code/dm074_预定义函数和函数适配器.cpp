#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	plus<int> intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x, y);
	cout << z << endl;

	plus<string> strAdd;
	string a = "aaa";
	string b = "bbb";
	string c = strAdd(a, b); 
	cout << c << endl;

	vector<string> s;
	s.push_back("aaa");
	s.push_back("bbb");
	s.push_back("ccc");
	s.push_back("bbb");
	s.push_back("bbb");
	s.push_back("aaa");

	string s1 = "bbb";

	int num = count_if(s.begin(), s.end(), bind2nd(equal_to<string>(), s1)); 
	//��Ԥ���庯������͹̶�������
	cout << "Num: " << num << endl;

	vector<int> v1;
	for (unsigned i = 0; i < 10; ++i)
	{
		v1.push_back(i + 1);
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//����������
	int num1 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "����: " << num1 << endl;

	//��ż��������not1��ʾȡ��
	int num2 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "ż��: " << num2 << endl;


	return 0;
}
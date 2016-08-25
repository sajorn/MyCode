#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//��ʼ��
	string s1 = "abcdefg";
	string s2("abcdabcd");
	string s3(10, 'a');
	
	//����
	for (unsigned i = 0; i < s1.length(); ++i)
	{
		cout << s1[i] << " "; //�����׳��쳣
	}
	cout << endl;

	try
	{
		for (unsigned i = 0; i < s1.length() + 1; ++i)
		{
			cout << s1.at(i) << " "; //��ͬ��s1[i],���ǻ��׳��쳣
		}
		cout << endl;
	}
	catch (...)
	{
		cout << "����Խ��" << endl;
	}

	//��������ʽ����
	for (string::iterator it = s3.begin(); it != s3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//string --> char*
	const char* pStr = s3.c_str();
	cout << pStr << endl;

	//����
	char buf[64] = { 0 };
	s1.copy(buf, 2, 0); //��0��λ�ÿ�ʼ������2��Ԫ�ص�buf��������
	cout << buf << endl;

	//��ֵ
	cout << "-----" << endl;
	const char* pChName = "abcd1234";
	string str1;
	str1.assign(pChName);
	cout << "str1 = " << str1 << endl;
	str1.assign(pChName, 5); //��ǰ5���ַ�������str
	cout << "str1 = " << str1 << endl;
	str1.assign(s1); //��string�ַ���������ȥ
	cout << "str1 = " << str1 << endl;
	str1.assign(s1, 0, 5); //����5���ַ�����ȥ
	cout << "str1 = " << str1 << endl;
	str1.assign(5, 'c'); //��n���ַ�cȥ����
	cout << "str1 = " << str1 << endl;
	cout << "-----" << endl;

	//����
	string s5 = "aaa";
	string s6 = "bbb";
	s5.append(s6); //���������ַ��� ��ͬ��:s5 = s5 + s6;
	cout << s5 << endl;

	//�ַ����ıȽ�
	cout << "----" << endl;
	int n = str1.compare(s5); // =1 ������ , =0 ��� =-1 ����С
	if (n == 0)
	{
		cout << "str1 == s5" << endl;
	}
	else if (n == 1)
	{
		cout << "str1 > s5" << endl;
	}
	else
	{
		cout << "str1 < s5" << endl;
	}

	cout << "----" << endl;
	//Ѱ���Ӵ�
	cout << "--Ѱ���Ӵ�" << endl;
	string str2 = "abcdefghijklmn";
	string sTmp = str2.substr(3, 7);
	cout << "sTmp = " << sTmp << endl;
	cout << endl;

	//�����ַ����±�, ͳ���Ӵ����ֵĴ��� rfind�Ƿ�������÷�һ��
	string s7 = "aayj 111 yj asdkh qwehjqyjqwe 132yj";
	unsigned unIndex = s7.find("yj", 0); //���±�0��ʼ��
	while (unIndex != string::npos)
	{
		cout << unIndex << endl;
		unIndex += strlen("yj");
		unIndex = s7.find("yj", unIndex); //���û�ҵ���Ӧ���ַ������򷵻�npos
	}

	//�滻��һ���ַ������Ӵ�
	unIndex = s7.find("yj", 0);
	while (unIndex != string::npos)
	{
		s7.replace(unIndex, strlen("yj"), "YJ");
		unIndex += strlen("yj");
		unIndex = s7.find("yj", unIndex);
	}
	cout << s7 << endl;

	//ɾ��ĳһ����������ַ���
	string s8 = "hello world";
	string::iterator it = find(s8.begin(), s8.end(), 'o');
	if (it != s8.end())
	{
		s8.erase(it);
	}
	cout << s8 << endl;
	s8.erase(s8.begin(), s8.end() - 1);
	cout << s8 << endl;

	//�����ַ���
	string s9 = "BBB";
	s9.insert(0, "aaa"); //ͷ�巨
	s9.insert(s9.length(), "ccc"); //β�巨
	cout << s9 << endl;

	//string�㷨 ȫ�����дȫ����Сд
	string s10 = "abcdABCD";
	transform(s10.begin(), s10.end(), s10.begin(), toupper); 
	//��һ����������ʾ�����ﵽ����ת����������������ʾת����Ľ����ŵ�λ�ã�
	//���ĸ�������ʾ���õĺ������ߺ�����ڵĵ�ַ
	cout << s10 << endl;
	transform(s10.begin(), s10.end(), s10.begin(), tolower);
	cout << s10 << endl;
	return 0;
}
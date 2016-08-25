/*
	�ͽ�ԭ������ƥ������
	˼�룺
	�ӵ�һ���ַ���ʼɨ��
	��ͨ�ַ������
	��������ţ���ѹջ
	�����ҷ��ţ����ջ
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool IsLeft(char ch) //left char
{
	bool isLeft = false;
	switch (ch)
	{
	case '<':
	case '(':
	case '[':
	case '{':
	case '/':
		isLeft = true;
		break;
	default:
		break;
	}
	return isLeft;
}

bool IsRight(char ch) //right char
{
	bool isRight = false;
	switch (ch)
	{
	case '>':
	case ')':
	case ']':
	case '}':
	case '/':
		isRight = true;
		break;
	default:
		break;
	}

	return isRight;
}

bool IsMatch(char left, char right)
{
	bool isMatch = false;
	switch (left)
	{
	case '<':
		isMatch = (right == '>');
		break;
	case '(':
		isMatch = (right == ')');
		break;
	case '[':
		isMatch = (right == ']');
		break;
	case '{':
		isMatch = (right == '}');
		break;
	case '/':
		isMatch = (right == '/');
		break;
	default:
		break;
	}

	return isMatch;
}

int Scanner(const char* str)
{
	stack<char> s;
	int i = 0;
	//ɨ���ַ���
	while (str[i] != '\0')
	{
		if (IsLeft(str[i]))
		{
			s.push(str[i]);
		}
		if (IsRight(str[i]) && !s.empty())
		{
			char c = s.top();
			if (c == '\0' || !IsMatch(c, str[i]))
			{
				cout << c << " and " << str[i] << " is not match!" << endl;
			}
			else
			{
				s.pop();
			}
		}
		i++;
	}

	if (s.empty())
	{
		cout << "Successful Match!" << endl;
	}
	else
	{
		cout << "Failed Match!" << endl;
	}
	
	return 0;
}

int main()
{
	char* str = "#include <stdio.h> int main(){ int a[5]; return 0; }";
	Scanner(str);

	return 0;
}
/*
	就近原则，括号匹配问题
	思想：
	从第一个字符开始扫描
	普通字符则忽略
	遇见左符号，则压栈
	遇见右符号，则出栈
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
	//扫描字符串
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
/*
遍历中缀表达式中的数字和符号
对于数字：直接输出
对于符号：
左括号：进栈
运算符号：与栈顶符号进行优先级比较
若栈顶符号优先级低：此符合进栈  （默认栈顶若是左括号，左括号优先级最低）
若栈顶符号优先级不低：将栈顶符号弹出并输出，之后进栈
右括号：将栈顶符号弹出并输出，直到匹配左括号
遍历结束：将栈中的所有符号弹出并输出
中缀转后缀

遍历后缀表达式中的数字和符号
对于数字：进栈
对于符号：
从栈中弹出右操作数
从栈中弹出左操作数
根据符号进行运算
将运算结果压入栈中
遍历结束：栈中的唯一数字为计算结果

*/
#include <iostream>
#include <cctype>
#include <stack>
using namespace std;

bool IsNum(char ch)
{
	return isdigit(ch);
}

bool IsOperator(char ch)
{
	bool isOperator = false;
	switch (ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		isOperator = true;
		break;
	default:
		break;
	}
	return isOperator;
}

bool IsLeftBracket(char ch)
{
	return (ch == '(');
}

bool IsRightBracket(char ch)
{
	return (ch == ')');
}

int Priority(char ch)
{
	int priority = 0;
	if (ch == '+' || ch == '-')
	{
		priority = 1;
	}
	if (ch == '*' || ch == '/')
	{
		priority = 2;
	}

	return priority;
}

//中缀转后缀
int TransForm(const char *str, char **out)
{
	stack<char> s;
	char *result = new char[256];
	int i = 0; //遍历字符串
	int j = 0; //保存后缀表达式
	//遍历字符串
	while (str[i] != '\0')
	{
		if (IsNum(str[i])) //数字直接弹出
		{
			result[j++] = str[i];
		}
		else if (IsOperator(str[i])) //操作符
		{
			if (s.empty())
			{
				s.push(str[i]); //直接入栈
			}
			else if (Priority(str[i]) <= Priority(s.top())) //栈顶元素优先级更高，先弹出在入栈
			{
				char c = s.top();
				s.pop();
				s.push(str[i]);
				s.push(c);
			}
			else
			{
				s.push(str[i]);
			}
		}
		else if (IsLeftBracket(str[i])) //左括弧入栈
		{
			s.push(str[i]);
		}
		else if (IsRightBracket(str[i]))
		{
			while (!IsLeftBracket(s.top()))
			{
				result[j++] = s.top();
				s.pop();
			}
			s.pop(); //做括弧出栈
		}
		i++;
	}

	while (!s.empty())
	{
		result[j++] = s.top();
		s.pop();
	}
	result[j] = '\0';

	*out = result;
	return 0;
}

int CharToInt(char ch)
{
	switch (ch)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}

int CalResult(int left, int right, char oper)
{
	int result = -1;
	switch (oper)
	{
	case '+':
		result = left + right;
		break;
	case '-':
		result = left - right;
		break;
	case '*':
		result = left * right;
		break;
	case '/':
		result = left / right;
		break;
	default:
		break;
	}
	return result;
}

//后缀计算
int Compute(const char *str)
{
	stack<char> s;
	int i = 0;
	while (str[i])
	{
		if (IsNum(str[i]))
		{	
			//数字直接压栈
			s.push(str[i]);
		}
		else if (IsOperator(str[i]))
		{
			int right = CharToInt(s.top());
			s.pop();
			int left = CharToInt(s.top());
			s.pop();
			int result = CalResult(left, right, str[i]); //计算表达式结果
			s.push(result);
		}
		i++;
	}
	if (s.size() == 1 && str[i] == '\0')
	{
		return s.top();
	}
	else
	{
		cout << "Failed Express" << endl;
		return -1;
	}
	return 0;
}

int main()
{
	char *str = "8+(3-1)*5"; 
	char *outStr = nullptr; //保存转换出的结果
	TransForm(str, &outStr); //转换出来结果为831-5*+
	int result = Compute(outStr);
	cout << "Result: " << result << endl;
	delete outStr;
	outStr = nullptr;

	char *str1 = "1+2*(66/(2*3)+7)";
	TransForm(str1, &outStr);
	result = Compute(outStr);
	cout << "Result: " << result << endl;
	delete outStr;
	outStr = nullptr;

	return 0;
}
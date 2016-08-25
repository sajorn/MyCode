/*
������׺���ʽ�е����ֺͷ���
�������֣�ֱ�����
���ڷ��ţ�
�����ţ���ջ
������ţ���ջ�����Ž������ȼ��Ƚ�
��ջ���������ȼ��ͣ��˷��Ͻ�ջ  ��Ĭ��ջ�����������ţ����������ȼ���ͣ�
��ջ���������ȼ����ͣ���ջ�����ŵ����������֮���ջ
�����ţ���ջ�����ŵ����������ֱ��ƥ��������
������������ջ�е����з��ŵ��������
��׺ת��׺

������׺���ʽ�е����ֺͷ���
�������֣���ջ
���ڷ��ţ�
��ջ�е����Ҳ�����
��ջ�е����������
���ݷ��Ž�������
��������ѹ��ջ��
����������ջ�е�Ψһ����Ϊ������

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

//��׺ת��׺
int TransForm(const char *str, char **out)
{
	stack<char> s;
	char *result = new char[256];
	int i = 0; //�����ַ���
	int j = 0; //�����׺���ʽ
	//�����ַ���
	while (str[i] != '\0')
	{
		if (IsNum(str[i])) //����ֱ�ӵ���
		{
			result[j++] = str[i];
		}
		else if (IsOperator(str[i])) //������
		{
			if (s.empty())
			{
				s.push(str[i]); //ֱ����ջ
			}
			else if (Priority(str[i]) <= Priority(s.top())) //ջ��Ԫ�����ȼ����ߣ��ȵ�������ջ
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
		else if (IsLeftBracket(str[i])) //��������ջ
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
			s.pop(); //��������ջ
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

//��׺����
int Compute(const char *str)
{
	stack<char> s;
	int i = 0;
	while (str[i])
	{
		if (IsNum(str[i]))
		{	
			//����ֱ��ѹջ
			s.push(str[i]);
		}
		else if (IsOperator(str[i]))
		{
			int right = CharToInt(s.top());
			s.pop();
			int left = CharToInt(s.top());
			s.pop();
			int result = CalResult(left, right, str[i]); //������ʽ���
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
	char *outStr = nullptr; //����ת�����Ľ��
	TransForm(str, &outStr); //ת���������Ϊ831-5*+
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
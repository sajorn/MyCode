#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class Context
{
public:
	void SetRes(int res)
	{
		m_res = res;
	}
	int GetRes()
	{
		return m_res;
	}
private:
	int m_res;
};

class Expression
{
public:
	virtual void Express(Context* context) = 0;
};

class PlusExpression : public Expression
{
public:
	void Express(Context* context)
	{
		int num = context->GetRes();
		num++;
		context->SetRes(num);
	}
};

class MinusExpression : public Expression
{
public:
	void Express(Context* context)
	{
		int num = context->GetRes();
		num--;
		context->SetRes(num);
	}
};

int main()
{
	Context* context = new Context;
	context->SetRes(10);
	Expression* plus = new PlusExpression;
	plus->Express(context);
	cout << context->GetRes() << endl;
	Expression* minus = new MinusExpression;
	minus->Express(context);
	cout << context->GetRes() << endl;
	return 0;
}
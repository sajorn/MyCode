#include <iostream>
#pragma warning(disable:4996)
using namespace std;

class Method
{
public:
	virtual void Dec() = 0;
};

class AEC : public Method
{
public:
	void Dec()
	{
		cout << "AEC Method" << endl;
	}
};

class DES : public Method
{
public:
	void Dec()
	{
		cout << "DES Method" << endl;
	}
};

class Context
{
public:
	void SetMethod(Method* method)
	{
		m_method = method;
	}
	void GetMethod()
	{
		m_method->Dec();
	}
private:
	Method* m_method;
};

int main()
{
	Method* method = new DES;
	Context* context = new Context;
	context->SetMethod(method);
	context->GetMethod();
	delete method;
	delete context;
	return 0;
}
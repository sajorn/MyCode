#include <iostream>

using namespace std;

class Test{
public:
	Test(int a = 0)
	{
		a_ = a;
		cout << "调用构造函数" << endl;
	}
	~Test()
	{
		cout << "调用析构函数" << endl;
	}
	Test(const Test& obj)
	{
		a_ = obj.a_ + 10;
	}
private:
	int a_;
};

void Print(Test tmp)//实参传给形参时会调用一次拷贝构造函数，函数结束后会把tmp析构
{
	cout << "打印tmp" << endl;
}

Test GetTest()
{
	Test tmp(4);
	return tmp; //返回的是匿名对象，原对象被销毁
}

int main()
{
	Test t1 = 1; //第一种调用
	Test t2(2); //第二种调用

	Test t3;//第三种调用
	Print(t3);

	Test t4 = GetTest(); //匿名对象直接转换成有名对象
	Test t5;
	t5 = GetTest(); //将匿名对象拷贝给t5对象，然后匿名对象析构。

	return 0;
}
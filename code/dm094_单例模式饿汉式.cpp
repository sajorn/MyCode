#include <iostream>
using namespace std;

class CSampleton
{
private:
	CSampleton() //1.定义私有的构造函数
	{
		;
	}

public:
	static CSampleton* ReturnSample() //提供全局访问
	{
		if (sample == NULL) //保证只有一个实例化
		{
			sample = new CSampleton;
		}
		return sample;
	}

private:
	static CSampleton* sample; //提供一个私有实例化指针对象
};

CSampleton* CSampleton::sample = NULL; //静态成员初始化
//CSampleton* CSampleton::sample = new CSampleton; //饿汉式，能避免单例模式的多线程问题
int main()
{
	CSampleton* s1 = CSampleton::ReturnSample();
	CSampleton* s2 = CSampleton::ReturnSample();
	if (s1 == s2)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "Not Equal" << endl;
	}
	return 0;
}
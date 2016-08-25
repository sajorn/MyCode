/*
	const_cast<>(): 移除常量性
	dynamic_cast<>(): 父子类之间多态的类型转换
	static_cast<>(): 会进行检查的隐式类型转换
	reinterpreter_cast<>(): 重新解释类型，强制性的类型转换,什么类型都能强转
*/

#include <iostream>
using namespace std;

class cAnimal
{
public:
	virtual void Bark() = 0;
};

class cDogs :public cAnimal
{
public:
	void Bark()
	{
		cout << "汪汪" << endl;
	}
};

class cCats :public cAnimal
{
public:
	void Bark()
	{
		cout << "喵喵" << endl;
	}
};

void WhoBark(cAnimal* animal)
{
	cDogs* pDogs = dynamic_cast<cDogs*>(animal); //可以知道具体是哪个子类，不是该子类则返回空
	if (pDogs != nullptr)
	{
		pDogs->Bark();
	}

	cCats* pCats = dynamic_cast<cCats*>(animal);
	if (pCats != nullptr)
	{
		pCats->Bark();
	}
}

int main()
{
	double x = 3.5;
	int y = static_cast<int>(x); //相当于C语言的 int y = (int)x;
	cout << y << endl;
	cout << "-------" << endl;
	const char* p = "hello";
	char* p1 = const_cast<char*>(p); //可以将const变量赋给非const，但是不允许修改
	//p1[0] = 'b'; //不允许
	cout << p1 << endl;
	cout << "-------" << endl;
	cDogs dog1;
	cCats cat1;
	WhoBark(&dog1);
	WhoBark(&cat1);
	return 0;
}
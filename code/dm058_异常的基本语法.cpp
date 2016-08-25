/*
	异常的基本语法，用throw抛出异常，用catch捕捉异常，也可以捕捉到不作处理继续抛出
*/

#include <iostream>
using namespace std;

void Divide(int x, int y)
{
	if (y == 0)
	{
		throw y; //将整型y抛出
	}
	cout << "x / y = " << x / y << endl;
}

int main()
{
	try
	{
		Divide(10, 2);
		Divide(100, 0);
	}
	catch (int e) //捕捉到返回整型的异常
	{
		cout << e << "不能作除数" << endl;
		//throw; //也可以不做处理继续扔
	}
	catch (...) //捕捉到返回除整型外的其他异常
	{
		cout << "未知错误" << endl;
	}

	return 0;
}
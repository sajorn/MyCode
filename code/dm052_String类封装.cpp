/*��װ�Լ���String��*/

#include <iostream>
using namespace std;

int main()
{
	char* p = new char(20);
	realloc(p, 30);
	delete[] p;
}
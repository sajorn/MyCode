#include <iostream>
using namespace std;

typedef struct stStack
{
	int data;
	int* top; //头部元素
	int* base; //底部元素
};
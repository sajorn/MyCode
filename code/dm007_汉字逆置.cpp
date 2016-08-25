/*
	你好世界 --->  界世好你
*/

#include <stdio.h>
#include <string.h>

#define ARMAX 128
int main()
{
	char cTest[ARMAX] = "你好世界";
	char cTest1[ARMAX] = "我是中国人";
	int len = strlen(cTest);
	int len1 = strlen(cTest1);

	int min = 0;
	int max = len-1;

	int min1 = 0;
	int max1 = len1-1;

	while (min < max)
	{
		char tmp = cTest[min];
		cTest[min] = cTest[max - 1];
		cTest[max - 1] = tmp;

		char tmp1 = cTest[min + 1];
		cTest[min + 1] = cTest[max];
		cTest[max] = tmp1;

		min += 2;
		max -= 2;
	}

	while (min1 < max1)
	{
		char tmp = cTest1[min1];
		cTest1[min1] = cTest1[max1 - 1];
		cTest1[max1 - 1] = tmp;

		char tmp1 = cTest1[min1 + 1];
		cTest1[min1 + 1] = cTest1[max1];
		cTest1[max1] = tmp1;

		min1 += 2;
		max1 -= 2;
	}

	printf("%s\n", cTest);
	printf("%s\n", cTest1);
	return 0;
}
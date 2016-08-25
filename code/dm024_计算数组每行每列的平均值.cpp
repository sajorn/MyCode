/*
	计算数组每行每列的平均值
*/

#include <stdio.h>

int main()
{
	int buf[3][5] = {
		{ 1, 3, 5, 6, 7 },
		{ 2, 4, 1, 3, 5 },
		{ 3, 2, 1, 4, 5 }
	};
	int hSum = 0;
	int sSum = 0;
	/*每一行*/
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d ", *(*(buf + i) + j));
			hSum += (*(*(buf + i) + j));
		}
		printf("= %.2lf\n", hSum/5.0);
		hSum = 0;
	}
	/*每一列*/
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%d ", *(*(buf + j) + i));
			sSum += (*(*(buf + j) + i));
		}
		printf("= %.2lf\n", sSum/3.0);
		sSum = 0;
	}
	
	return 0;
}
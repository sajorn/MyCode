/*
教堂来了A，B，C 3个新郎和X，Y，Z 3个新娘，问新人中的3位，他们互相与谁结婚。下面是3个人的回答，
但全是假话，判断他们谁与谁结婚。

A说他与X结婚；
X说她与C结婚；
C说他与Z结婚。
*/

#define PEOPLE_NUM 3
#include <stdio.h>

int main()
{
	char cWife[PEOPLE_NUM] = { 'X', 'Y', 'Z' }; //新娘
	char cHusband[PEOPLE_NUM] = { 'A', 'B', 'C' }; //新郎

	//列出新娘所有的可能性
	for (int i = 0; i < PEOPLE_NUM; ++i) //cWife[0]
	{
		for (int j = 0; j < PEOPLE_NUM; ++j) //cWife[1]
		{
			for (int k = 0; k < PEOPLE_NUM; ++k) //cWife[2]
			{
				// 上述列出的结果为 XXX, XXY, XXZ ... ZZY, ZZZ
				// 将重复的结果剔除
				if (i == k || i == j || k == j)
				{
					continue;
					// 得到的结果为 XYZ, XZY,	YXZ, YZX, ZYX, ZXY
				}
				
				// 将上述所得的结果匹配给新郎
				// 1. A说他与X结婚
				if (cWife[i] == 'X') continue;
				// 2. X说她与C结婚
				if (cWife[k] == 'X') continue;
				// 3. C说他与Z结婚
				if (cWife[k] == 'Z') continue;
				//将符合的结果赋给cTempWife中
				char cTempWife[PEOPLE_NUM] = { cWife[i], cWife[j], cWife[k] };

				for (int l = 0; l < PEOPLE_NUM; ++l)
				{
					printf("Match %c -----> %c\n", cHusband[l], cTempWife[l]);
				}

				
			}								
		}
	}
	//
	return 0;
}

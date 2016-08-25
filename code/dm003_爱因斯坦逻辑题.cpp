/*
1.在一条街上，有5座房子，喷了5种颜色。
2.每个房子里住着不同国籍的人。
3.每个人喝着不同的饮料，抽不同品牌的香烟，养不同的宠物。
问题是：谁养鱼？

提示：
1、英国人住红色房子。
2、瑞典人养狗。
3、丹麦人喝茶。
4、绿色房子在白色房子左面。
5、绿色房子主人喝咖啡。
6、抽Pall Mall香烟的人养鸟。
7、黄色房子主人抽Dunhill香烟。
8、住在中间房子的人喝牛奶。
9、挪威人住第一间房。
10、抽Blends香烟的人住在养猫的人隔壁。
11、养马的人住抽Dunhill香烟的人隔壁。
12、抽Blue Master的人喝啤酒。
13、德国人抽Prince香烟。
14、挪威人住蓝色房子隔壁。
15、抽Blends香烟的人有一个喝水的邻居。

*/

#include <stdio.h>
#include <string.h>

#define SUM 5 //总数
#define ALL_ARRANGE 120 //总的排列组合
#define ARRAY_LEN 20

//枚举所有内容
enum HOUSE {
	red, green, white, yellow, blue
}; //房子颜色
char houseList[5][4] = { "红", "绿", "白", "黄", "蓝" };

enum NATION {
	English, Swede, Danes, Norse, Dutchman
}; //国籍
char nationList[5][4] = { "英", "瑞", "丹", "挪", "德" };

enum DRINK {
	tea, coffee, milk, beer, water
}; //饮料
char drinkList[5][4] = { "茶", "咖", "奶", "酒", "水" };

enum CIGARETTE {
	pallMall, dunHill, blueMaster, prince, blends
}; //香烟
char cigaretteList[5][4] = { "PM", "DH", "BM", "PE", "BS" };

enum PET {
	dog, bird, cat, horse, fish
}; //宠物
char petList[5][4] = { "狗", "鸟", "猫", "马", "鱼" };

int allArray[ALL_ARRANGE][SUM]; //存放所有可能的结果

void InitArray() //排列组合出所有可能的情况
{
	int index = 0;
	for (int a = 0; a < SUM; ++a)
	{
		for (int b = 0; b < SUM; ++b)
		{
			if (a == b)	continue;

			for (int c = 0; c < SUM; ++c)
			{
				if (c == a || c == b) continue;

				for (int d = 0; d < SUM; ++d)
				{
					if (d == a || d == b || d == c) continue;

					for (int e = 0; e < SUM; ++e)
					{
						if (e == a || e == b || e == c || e == d) continue;

						int tmpArray[SUM] = { a, b, c, d, e };				
						memcpy(allArray[index], tmpArray, ARRAY_LEN);
						index++;
						
					}
				}
			}
		}
	}
	return;
}

bool MatchArray(int arr1[], int arr2[], int key1, int key2) //匹配结果
{
	for (int i = 0; i < SUM; ++i)
	{
		if (arr1[i] == key1 && arr2[i] == key2)
		{
			return true;
		}
	}
	return false;
}

bool MatchLocation(int arr1[], int arr2[], 
	int left, int right, bool isNear) //匹配位置,可能相邻可能不相邻
{
	if (!isNear) //不相邻时
	{
		for (int i = 0; i < SUM; ++i)
		{
			if (arr1[i] == left)
			{
				for (int j = i + 1; j < SUM; ++j)
				{
					if (arr2[j] == right)
					{
						return true;
					}
				}
			}
		}
	}
	else //相邻时
	{
		for (int i = 0; i < SUM; ++i)
		{
			if (arr1[i] == left)
			{
				if (i < SUM && arr2[i + 1] == right)
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool MatchNearby(int arr1[], int arr2[], int left, int right) //匹配隔壁
{
	for (int i = 0; i < SUM; i++)
	{
		if (arr1[i] == left)
		{
			if (i < SUM && arr2[i + 1] == right)
			{ 
				return true;
			}
			
		}
		else if (arr2[i] == right)
		{
			if (i < SUM && arr1[i + 1] == left)
			{
				return true;
			}
		}
	}
	return false;
}

void OutPut(int arr[5], char show[5][4])
{
	for (int i = 0; i < 5; ++i)
	{
		int x = arr[i];
		printf("%s ", show[x]);
	}
	printf("\n");
}

void GetAnswer() //找出答案
{
	int iHouse[SUM];
	int iNation[SUM];
	int iDrink[SUM];
	int iCigaretee[SUM];
	int iPet[SUM];

	int iCnt = 1;

	for (int a = 0; a < ALL_ARRANGE; ++a) //房子颜色
	{
		memcpy(iHouse, allArray[a], ARRAY_LEN); //将第a种情况赋给iHouse

		//4、绿色房子在白色房子左面。
		if (!MatchLocation(iHouse, iHouse, green, white, true)) continue;

		for (int b = 0; b < ALL_ARRANGE; ++b) //国籍
		{
			memcpy(iNation, allArray[b], ARRAY_LEN); //将第b种情况赋给iNation

			//9、挪威人住第一间房。
			if (iNation[0] != Norse) continue;

			//1、英国人住红色房子。
			if (!MatchArray(iNation, iHouse, English, red)) continue;

			//14、挪威人住蓝色房子隔壁。
			if (!MatchNearby(iNation, iHouse, Norse, blue)) continue;

			for (int c = 0; c < ALL_ARRANGE; ++c) //饮料
			{
				memcpy(iDrink, allArray[c], ARRAY_LEN); //将第c种情况赋给iDrink

				//8、住在中间房子的人喝牛奶。
				if (iDrink[2] != milk) continue;

				//3、丹麦人喝茶
				if (!MatchArray(iNation, iDrink, Danes, tea)) continue;

				//5、绿色房子主人喝咖啡。
				if (!MatchArray(iHouse, iDrink, green, coffee)) continue;

				for (int d = 0; d < ALL_ARRANGE; ++d) //香烟
				{
					memcpy(iCigaretee, allArray[d], ARRAY_LEN); //将第d种情况赋给iCigaretee

					//7、黄色房子主人抽Dunhill香烟。
					if (!MatchArray(iHouse, iCigaretee, yellow, dunHill)) continue;

					//12、抽Blue Master的人喝啤酒。
					if (!MatchArray(iCigaretee, iDrink, blueMaster, beer)) continue;

					//13、德国人抽Prince香烟。
					if (!MatchArray(iNation, iCigaretee, Dutchman, prince)) continue;

					//15、抽Blends香烟的人有一个喝水的邻居。
					if (!MatchNearby(iCigaretee, iDrink, blends, water)) continue;

					for (int e = 0; e < ALL_ARRANGE; ++e) //宠物
					{
						memcpy(iPet, allArray[e], ARRAY_LEN); //将第e种情况赋给iPet

						//2、瑞典人养狗。
						if (!MatchArray(iNation, iPet, Swede, dog)) continue;

						//6、抽Pall Mall香烟的人养鸟。
						if (!MatchArray(iCigaretee, iPet, pallMall, bird)) continue;

						//10、抽Blends香烟的人住在养猫的人隔壁。
						if (!MatchNearby(iCigaretee, iPet, blends, cat)) continue;

						//11、养马的人住抽Dunhill香烟的人隔壁。
						if (!MatchNearby(iPet, iCigaretee, horse, dunHill)) continue;

						printf("第%d种结果:\n", iCnt);
						OutPut(iHouse, houseList);
						OutPut(iNation, nationList);
						OutPut(iCigaretee, cigaretteList);
						OutPut(iDrink, drinkList);
						OutPut(iPet, petList);
						printf("\n");
						iCnt++;
					}
				}
			}
		}
	}
	
}

int main()
{
	InitArray();
	GetAnswer();
	printf("Done!\n");
	return 0;
}
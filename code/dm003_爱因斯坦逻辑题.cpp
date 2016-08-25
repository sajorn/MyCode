/*
1.��һ�����ϣ���5�����ӣ�����5����ɫ��
2.ÿ��������ס�Ų�ͬ�������ˡ�
3.ÿ���˺��Ų�ͬ�����ϣ��鲻ͬƷ�Ƶ����̣�����ͬ�ĳ��
�����ǣ�˭���㣿

��ʾ��
1��Ӣ����ס��ɫ���ӡ�
2�������������
3�������˺Ȳ衣
4����ɫ�����ڰ�ɫ�������档
5����ɫ�������˺ȿ��ȡ�
6����Pall Mall���̵�������
7����ɫ�������˳�Dunhill���̡�
8��ס���м䷿�ӵ��˺�ţ�̡�
9��Ų����ס��һ�䷿��
10����Blends���̵���ס����è���˸��ڡ�
11���������ס��Dunhill���̵��˸��ڡ�
12����Blue Master���˺�ơ�ơ�
13���¹��˳�Prince���̡�
14��Ų����ס��ɫ���Ӹ��ڡ�
15����Blends���̵�����һ����ˮ���ھӡ�

*/

#include <stdio.h>
#include <string.h>

#define SUM 5 //����
#define ALL_ARRANGE 120 //�ܵ��������
#define ARRAY_LEN 20

//ö����������
enum HOUSE {
	red, green, white, yellow, blue
}; //������ɫ
char houseList[5][4] = { "��", "��", "��", "��", "��" };

enum NATION {
	English, Swede, Danes, Norse, Dutchman
}; //����
char nationList[5][4] = { "Ӣ", "��", "��", "Ų", "��" };

enum DRINK {
	tea, coffee, milk, beer, water
}; //����
char drinkList[5][4] = { "��", "��", "��", "��", "ˮ" };

enum CIGARETTE {
	pallMall, dunHill, blueMaster, prince, blends
}; //����
char cigaretteList[5][4] = { "PM", "DH", "BM", "PE", "BS" };

enum PET {
	dog, bird, cat, horse, fish
}; //����
char petList[5][4] = { "��", "��", "è", "��", "��" };

int allArray[ALL_ARRANGE][SUM]; //������п��ܵĽ��

void InitArray() //������ϳ����п��ܵ����
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

bool MatchArray(int arr1[], int arr2[], int key1, int key2) //ƥ����
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
	int left, int right, bool isNear) //ƥ��λ��,�������ڿ��ܲ�����
{
	if (!isNear) //������ʱ
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
	else //����ʱ
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

bool MatchNearby(int arr1[], int arr2[], int left, int right) //ƥ�����
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

void GetAnswer() //�ҳ���
{
	int iHouse[SUM];
	int iNation[SUM];
	int iDrink[SUM];
	int iCigaretee[SUM];
	int iPet[SUM];

	int iCnt = 1;

	for (int a = 0; a < ALL_ARRANGE; ++a) //������ɫ
	{
		memcpy(iHouse, allArray[a], ARRAY_LEN); //����a���������iHouse

		//4����ɫ�����ڰ�ɫ�������档
		if (!MatchLocation(iHouse, iHouse, green, white, true)) continue;

		for (int b = 0; b < ALL_ARRANGE; ++b) //����
		{
			memcpy(iNation, allArray[b], ARRAY_LEN); //����b���������iNation

			//9��Ų����ס��һ�䷿��
			if (iNation[0] != Norse) continue;

			//1��Ӣ����ס��ɫ���ӡ�
			if (!MatchArray(iNation, iHouse, English, red)) continue;

			//14��Ų����ס��ɫ���Ӹ��ڡ�
			if (!MatchNearby(iNation, iHouse, Norse, blue)) continue;

			for (int c = 0; c < ALL_ARRANGE; ++c) //����
			{
				memcpy(iDrink, allArray[c], ARRAY_LEN); //����c���������iDrink

				//8��ס���м䷿�ӵ��˺�ţ�̡�
				if (iDrink[2] != milk) continue;

				//3�������˺Ȳ�
				if (!MatchArray(iNation, iDrink, Danes, tea)) continue;

				//5����ɫ�������˺ȿ��ȡ�
				if (!MatchArray(iHouse, iDrink, green, coffee)) continue;

				for (int d = 0; d < ALL_ARRANGE; ++d) //����
				{
					memcpy(iCigaretee, allArray[d], ARRAY_LEN); //����d���������iCigaretee

					//7����ɫ�������˳�Dunhill���̡�
					if (!MatchArray(iHouse, iCigaretee, yellow, dunHill)) continue;

					//12����Blue Master���˺�ơ�ơ�
					if (!MatchArray(iCigaretee, iDrink, blueMaster, beer)) continue;

					//13���¹��˳�Prince���̡�
					if (!MatchArray(iNation, iCigaretee, Dutchman, prince)) continue;

					//15����Blends���̵�����һ����ˮ���ھӡ�
					if (!MatchNearby(iCigaretee, iDrink, blends, water)) continue;

					for (int e = 0; e < ALL_ARRANGE; ++e) //����
					{
						memcpy(iPet, allArray[e], ARRAY_LEN); //����e���������iPet

						//2�������������
						if (!MatchArray(iNation, iPet, Swede, dog)) continue;

						//6����Pall Mall���̵�������
						if (!MatchArray(iCigaretee, iPet, pallMall, bird)) continue;

						//10����Blends���̵���ס����è���˸��ڡ�
						if (!MatchNearby(iCigaretee, iPet, blends, cat)) continue;

						//11���������ס��Dunhill���̵��˸��ڡ�
						if (!MatchNearby(iPet, iCigaretee, horse, dunHill)) continue;

						printf("��%d�ֽ��:\n", iCnt);
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
/*
��������A��B��C 3�����ɺ�X��Y��Z 3������������е�3λ�����ǻ�����˭��顣������3���˵Ļش�
��ȫ�Ǽٻ����ж�����˭��˭��顣

A˵����X��飻
X˵����C��飻
C˵����Z��顣
*/

#define PEOPLE_NUM 3
#include <stdio.h>

int main()
{
	char cWife[PEOPLE_NUM] = { 'X', 'Y', 'Z' }; //����
	char cHusband[PEOPLE_NUM] = { 'A', 'B', 'C' }; //����

	//�г��������еĿ�����
	for (int i = 0; i < PEOPLE_NUM; ++i) //cWife[0]
	{
		for (int j = 0; j < PEOPLE_NUM; ++j) //cWife[1]
		{
			for (int k = 0; k < PEOPLE_NUM; ++k) //cWife[2]
			{
				// �����г��Ľ��Ϊ XXX, XXY, XXZ ... ZZY, ZZZ
				// ���ظ��Ľ���޳�
				if (i == k || i == j || k == j)
				{
					continue;
					// �õ��Ľ��Ϊ XYZ, XZY,	YXZ, YZX, ZYX, ZXY
				}
				
				// ���������õĽ��ƥ�������
				// 1. A˵����X���
				if (cWife[i] == 'X') continue;
				// 2. X˵����C���
				if (cWife[k] == 'X') continue;
				// 3. C˵����Z���
				if (cWife[k] == 'Z') continue;
				//�����ϵĽ������cTempWife��
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

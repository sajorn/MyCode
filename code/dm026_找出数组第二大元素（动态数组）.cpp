/*
	��̬����ʵ���ҳ�����ڶ���Ԫ��
*/

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

int main()
{
	int numMax;
	puts("���������С:");
	scanf("%d", &numMax);
	int* arr = (int*)calloc(numMax, sizeof(int));
	
	int index;
	for (index = 0; index < numMax; ++index)
	{
		printf("array[%d] = ", index + 1);
		scanf("%d", &arr[index]);
	}

	int iFirstMax = INT_MIN;
	int iSecondMax = INT_MIN;

	for (index = 0; index < numMax; ++index)
	{
		if (iFirstMax < arr[index])
		{
			iSecondMax = iFirstMax;
			iFirstMax = arr[index];
		}
		if (iSecondMax < arr[index] && iFirstMax > arr[index])
		{
			iSecondMax = arr[index];
		}
	}
	printf("��һ�������%d\n", iFirstMax);
	printf("�ڶ������: %d\n", iSecondMax);

	free(arr);
	return 0;
}
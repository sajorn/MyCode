#include <stdio.h>
#pragma warning(disable:4996)
void code(char* s) //º”√‹
{
	while (*s)
	{
		(*s)++;
		s++;
	}
}

void decode(char* s) //Ω‚√‹
{
	while (*s)
	{
		(*s)--;
		s++;
	}
}

int main()
{
	FILE* fp = fopen("code_source.txt", "r");
	if (fp < 0)
	{
		printf("open error\n");
		return 0;
	}
	
	FILE* fp2 = fopen("code_code.txt", "w");
	if (fp2 < 0)
	{
		printf("open error\n");
		return 0;
	}

	FILE* fp3 = fopen("code_decode.txt", "w");
	if (fp3 < 0)
	{
		printf("open error\n");
		return 0;
	}

	while (!feof(fp))
	{
		char cBuf[128] = { 0 };
		fgets(cBuf, sizeof(cBuf), fp);
		code(cBuf);
		fputs(cBuf, fp2);
		decode(cBuf);
		fputs(cBuf, fp3);
	}
	
	fclose(fp);
	fclose(fp2);
	fclose(fp3);

	printf("Done!\n");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#pragma warning(disable:4996)

int main()
{
	clock_t mTime1 = clock(); //获取当前的系统时间

	struct stat st = { 0 };
	FILE* fp = fopen("copy_source.exe", "rb");
	if (!fp)
	{
		printf("open error!\n");
		return 0;
	}

	stat("copy_source.exe", &st); //将第一个参数的文件信息传给第二个参数stat结构体中保存
	long fLen = st.st_size; //得到该文件的大小

	char* buf = (char*)malloc(fLen);
	fread(buf, sizeof(char), fLen, fp);
	fclose(fp);

	fp = fopen("copy_after.exe", "wb");
	if (!fp)
	{
		printf("open error\n");
		return 0;
	}

	fwrite(buf, sizeof(char), fLen, fp);
	fclose(fp);
	free(buf);

	clock_t mTime2 = clock();

	printf("Done! Use Time: %d ms\n", mTime2 - mTime1);
	return 0;
}
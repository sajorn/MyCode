/*
	œ»–Úµ›πÈ∫Õ∫Û–Úµ›πÈ
*/

#include <stdio.h>

int MulNum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		printf("%d\n", n);
		MulNum(--n);
		printf("%d\n", n);
	}

}

int main()
{
	int n = 4;
	MulNum(n);
	return 0;
}
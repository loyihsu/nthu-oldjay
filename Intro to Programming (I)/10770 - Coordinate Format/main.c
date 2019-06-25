// Problem: http://140.114.86.238/problem/10770/
#include <stdio.h>

int main(void)
{
	int h, w;
	int i, j;
	int grid[100][100] = {0};
	scanf("%d %d", &h, &w);

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (grid[i][j] != 0)
				printf("%d %d %d\n", i, j, grid[i][j]);
		}
	}

	return 0;
}

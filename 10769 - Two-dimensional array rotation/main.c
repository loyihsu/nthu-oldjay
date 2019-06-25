// Problem: http://140.114.86.238/problem/10769/
#include <stdio.h>

int main(void)
{
	int grid[20][20];
	int i, j, n;
	int trans[39][39] = {0};

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &grid[i][j]);
		}
	}

	//trans
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			trans[i + j][j] = grid[i][j];
			j++;
		}
		i++;
	}

	//print upper
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i + 1; j++)
		{
			if (j == i)
			{
				printf("%d\n", trans[i][j]);
			}
			else
			{
				printf("%d ", trans[i][j]);
			}
		}
	}

	for (i = n; i < 2 * n; i++)
	{
		for (j = 0; j < 5; j++)
		{
			while (trans[i][j] == 0)
				j++;
			while (trans[i][j] != 0 && j < n - 1)
				printf("%d ", trans[i][j++]);
			if (j == n - 1)
			{
				printf("%d\n", trans[i][j]);
			}
		}
	}
	return 0;
}
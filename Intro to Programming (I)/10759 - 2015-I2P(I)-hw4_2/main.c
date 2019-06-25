// Problem: http://140.114.86.238/problem/10759/
#include <stdio.h>

int main(void)
{
	int N, cubea[18][9];
	int i, j, k;
	int output[9][9];

	scanf("%d", &N);

	//get values
	for (i = 0; i<2*N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (j != N-1)
			{
				scanf("%d ", &cubea[i][j]);
			}
			if (j == N-1)
			{
				scanf("%d\n", &cubea[i][j]);
			}
		}
	}
	
	//working
	for (i = 0, k = N; i<N, k<2*N; i++, k++)
	{
		for (j = 0; j<=N; j++)
		{
			output[i][j] = (cubea[i][j]<=cubea[k][j])?cubea[i][j]:cubea[k][j];
		}
	}
	
	//printing
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (j!= N-1)
			{
				printf("%d ", output[i][j]);
			} else {
				printf("%d\n", output[i][j]);
			}
		}
	}
	
	return 0;
}
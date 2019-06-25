// Problem: http://140.114.86.238/problem/10097/
#include <stdio.h>

long trinary(int);

int main(void)
{
	int num, stand, i, w;
	int d, rd, e, re, f, rf, g, rg, h, rh, l, ri, j, rj, k;
	scanf("%d %d", &num, &stand);
	int tnum[stand], trnum[stand];
	d = num / 2187;
	rd = num % 2187;
	e = rd / 729;
	re = rd % 729;
	f = re / 243;
	rf = re % 243;
	g = rf / 81;
	rg = rf % 81;
	h = rg / 27;
	rh = rg % 27;
	l = rh / 9;
	ri = rh % 9;
	j = ri / 3;
	rj = ri % 3;
	k = rj / 1;

	tnum[0] = d; //7
	tnum[1] = e; //6
	tnum[2] = f; //5
	tnum[3] = g; //4
	tnum[4] = h; //3
	tnum[5] = l; //2
	tnum[6] = j; //1
	tnum[7] = k; //0

	w = 0;
	while (w <= stand)
	{
		trnum[w] = tnum[7 - w];
		w = w + 1;
	}

	i = 1;
	while (i <= stand)
	{
		printf("%d", trnum[stand - i]);
		i = i + 1;
	}
	printf("\n");
}

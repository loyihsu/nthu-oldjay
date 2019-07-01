// Problem: http://140.114.86.238/problem/10067/
#include <stdio.h>

int main(void)
{
	int n[3];

	scanf("%1d%1d%1d", &n[0], &n[1], &n[2]);
	printf("%c%c%c", n[0] + 'A' - 1, n[1] + 'A' - 1, n[2] + 'A' - 1);	

	return 0;
}

// Problem: http://140.114.86.238/problem/10716/
#include <stdio.h>

int main(void) {
	int a, n, d;

	scanf("%d%d%d", &a, &n, &d);
	printf("%d %d", a+(n-1)*d, (2*a+(n-1)*d)*n/2);

	return 0;
}

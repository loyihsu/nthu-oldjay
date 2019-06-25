// Problem: http://140.114.86.238/status/view_code/1263983
#include <stdio.h>

float reverse(float);

int main(void)
{
	float num, snum, avg;
	scanf("%f", &num);
	snum = reverse(num);
	avg = (num + snum) / 2;
	printf("%.1f", avg);
	return 0;
}

float reverse(float x)
{
	int a, b, c;
	a = x / 100;
	b = (x / 10) - (10 * a);
	c = x - (100 * a) - (10 * b);
	return 100 * c + 10 * b + a;
}

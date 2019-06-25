// Problem: http://140.114.86.238/problem/10067/
#include <stdio.h>

int main(void)
{
	int name, a, b, c;
	scanf("%d", &name);
	a = (name / 100);
	b = (name / 10) - (a * 10);
	c = name - (100 * a) - (10 * b);
	if (a >= 1 && a <= 9)
	{
		printf("%c", a + 64);
	}
	
	if (a == 0)
	{
		printf("%c", a + 74);
	}

	if (b >= 1 && b <= 9)
	{
		printf("%c", b + 64);
	} else if (b == 0)
	{
		printf("%c", b + 74);
	}
	
	if (c >= 1 && c <= 9)
	{
		printf("%c", c + 64);
	} else if (c == 0)
	{
		printf("%c", c + 74);
	}
	return 0;
}

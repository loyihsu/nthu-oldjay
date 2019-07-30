// Problem: http://140.114.86.238/problem/1000/
#include <stdio.h>

int main(void) {
	int a, b;

	while(scanf("%d %d", &a, &b) != EOF)	// Getting input until EOF
		printf("%d\n", a+b);
		
	return 0;
}
		    

#include <stdio.h>
#include "function.h"

int main(void) {

	int **mat;
	int m, n, i;

	scanf("%d %d", &m, &n);

	mat = allocateMat(m, n);
	readInput(mat, m, n);
	printResult(mat, m, n);

	for(i=0; i<m; i++)
		free(mat[i]);
	free(mat);

	return 0;
}

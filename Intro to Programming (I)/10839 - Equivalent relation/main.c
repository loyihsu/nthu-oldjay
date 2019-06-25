#include <stdio.h>
#include "function.h"

#define SIZE 100

int main() {
	int *ptrArr[SIZE];
	int dataArr[SIZE] = {0};
	char inst;
	int dataNum, instNum;
	int param1, param2;
	int i;

	/* input */
	scanf("%d %d", &dataNum, &instNum);

	/* initialize the ptrArr */
	for (i = 0; i < dataNum; i++)
		ptrArr[i] = &dataArr[i];

	for (i = 0; i < instNum; i++) {
		scanf(" %c %d %d", &inst, &param1, &param2);

		execInst(ptrArr, inst, param1, param2);
	}

	/* output */
	for (i = 0; i < dataNum - 1; i++) {
		printf("%d ", *ptrArr[i]);
	}
	printf("%d", *ptrArr[i]);

	return 0;
}

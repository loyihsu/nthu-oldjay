#include <stdio.h>
#include "function.h"

#define SIZE 100

int main() {
	int *ptrArr[SIZE], dataArr[SIZE] = {0};
	char inst;
	int dataNum, instNum, i, param1, param2;

	scanf("%d %d", &dataNum, &instNum);
	
	// Initialize the ptrArr
	for (i = 0; i < dataNum; i++)		
		ptrArr[i] = &dataArr[i];

	for (i = 0; i < instNum; i++) {
		scanf(" %c %d %d", &inst, &param1, &param2);

		execInst(ptrArr, inst, param1, param2);
	}

	for (i = 0; i < dataNum - 1; i++)
		printf("%d ", *ptrArr[i]);
	printf("%d", *ptrArr[i]);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		for(j = 0; ; j++) {
			scanf("%d", &NPClist[i][j]);
			if(NPClist[i][j] == 0) break;
		}
	}
	findNPC(1);
	
	return 0;
}

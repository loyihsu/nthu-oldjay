// Problem: http://140.114.86.238/problem/10849/
#include <stdio.h>
#include <stdlib.h>

char **tangram;
void square(int, int, int, int);
void triangle(int, int, int, int);

int main(void) {
    int height, width, degree, size, tanX, tanY, i, j;
    char symbol;
    
    scanf("%d%d", &height, &width);
    
    tangram = (char**) malloc(sizeof(char*) * height);
    for (i = 0; i < height; i++)
        tangram[i] = (char*) malloc(sizeof(char) * width);
    
    for (i = 0; i < height; i++)
        for (j = 0; j < width; j++)
            tangram[i][j] = '-';
    
    while (scanf("%c", &symbol) && symbol != 'x') {
        scanf("%d%d%d%d", &degree, &size, &tanX, &tanY);
        if (symbol == 'T') {
            triangle(degree, size, tanX, tanY);
        } else if (symbol == 'Q') {
            square(degree, size, tanX, tanY);
        }
    }
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++)
            printf("%c", tangram[i][j]);
        printf("\n");
    }
    
    return 0;
}

void square(int rotate, int side, int verX, int verY) {
    int i, j;
    
    if (rotate == 0) {
        for (i = verX-side+1; i < verX+1; i++)
            for (j = verY-side+1; j < verY+1; j++)
                tangram[i][j] = 'Q';
    } else if (rotate == 90) {
        for (i = verX-side+1; i < verX+1; i++)
            for (j = verY; j < verY+side; j++)
                tangram[i][j] = 'Q';
    } else if (rotate == 180) {
        for (i = verX; i < verX + side; i++)
            for (j = verY; j < verY + side; j++)
                tangram[i][j] = 'Q';
    } else if (rotate == 270) {
        for (i = verX; i < verX + side; i++)
            for (j = verY-side+1; j < verY+1; j++)
                tangram[i][j] = 'Q';
    }
    tangram[verX][verY] = 'q';
}

void triangle(int rotate, int side, int verX, int verY) {
    int i, j;
    
    if (rotate == 0) {
        for (i = 0; i < side; i++) {
            tangram[verX-i][verY] = 'T';
            for (j = 0; j <= i; j++) {
                tangram[verX-i][verY+j] = 'T';
                tangram[verX-i][verY-j] = 'T';
            }
        }
    } else if (rotate == 90) {
        for (i = 0; i < side; i++) {
            tangram[verX][verY+i] = 'T';
            for (j = 0; j <= i; j++) {
                tangram[verX+j][verY+i] = 'T';
                tangram[verX-j][verY+i] = 'T';
            }
        }
    } else if (rotate == 180) {
        for (i = 0; i < side; i++) {
            tangram[verX+i][verY] = 'T';
            for (j = 0; j <= i; j++) {
                tangram[verX+i][verY+j] = 'T';
                tangram[verX+i][verY-j] = 'T';
            }
        }
    } else if (rotate == 270) {
        for (i = 0; i < side; i++) {
            tangram[verX][verY-i] = 'T';
            for (j = 0; j <= i; j++) {
                tangram[verX+j][verY-i] = 'T';
                tangram[verX-j][verY-i] = 'T';
            }
        }
    }
    tangram[verX][verY] = 't';
}
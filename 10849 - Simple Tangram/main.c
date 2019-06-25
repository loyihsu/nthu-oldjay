// Problem: http://140.114.86.238/problem/10849/
#include <stdio.h>

char tangram[501][501];
void square(int, int, int, int);
void triangle(int, int, int, int);

int main(void)
{
    int x, y;
    int rotate, side, verx, very;
    char word;
    
    int i,j;
    
    scanf("%d%d", &x, &y);
    
    for (i = 0; i<= x; i++)
    {
        for (j = 0; j <= y; j++)
        {
            tangram[i][j] = '-';
        }
    }
    
    while (word != 'x')
    {
        scanf("%c", &word);
        if (word == 'T')
        {
            scanf("%d%d%d%d", &rotate, &side, &verx, &very);
            triangle(rotate, side, verx, very);
        } else if (word == 'Q')
        {
            scanf("%d%d%d%d", &rotate, &side, &verx, &very);
            square(rotate, side, verx, very);
        }
    }
    
    for (i = 0; i<x; i++)
    {
        for (j = 0; j<y; j++)
        {
            printf("%c", tangram[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void square(int rotate, int side, int verx, int very)
{
    int i, j;
    
    if (rotate == 0)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j<=i; j++)
            {
                tangram[verx-i][very] = 'Q';
                tangram[verx-j][very-i] = 'Q';
                tangram[verx-i][very-j] = 'Q';
                tangram[verx][very-i] = 'Q';
                tangram[verx][very] = 'q';
            }
        }
    } else if (rotate == 90)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j<=i; j++)
            {
                tangram[verx-i][very] = 'Q';
                tangram[verx-j][very+i] = 'Q';
                tangram[verx-i][very+j] = 'Q';
                tangram[verx][very+i] = 'Q';
                tangram[verx][very] = 'q';
            }
        }
    } else if (rotate == 180)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j<=i; j++)
            {
                tangram[verx+i][very] = 'Q';
                tangram[verx+j][very+i] = 'Q';
                tangram[verx+i][very+j] = 'Q';
                tangram[verx][very+i] = 'Q';
                tangram[verx][very] = 'q';
            }
        }
    } else if (rotate == 270)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j<=i; j++)
            {
                tangram[verx][very-i] = 'Q';
                tangram[verx+j][very-i] = 'Q';
                tangram[verx+i][very-j] = 'Q';
                tangram[verx+i][very] = 'Q';
                tangram[verx][very] = 'q';
            }
        }
    }
    
    return;
}
void triangle(int rotate, int side, int verx, int very)
{
    int i,j;
    
    if (rotate == 0)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j<=i; j++)
            {
                tangram[verx-i][very] = 'T';
                tangram[verx-i][very+j] = 'T';
                tangram[verx-i][very-j] = 'T';
                tangram[verx][very] = 't';
            }
        }
    } else if (rotate == 90)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j<=i; j++)
            {
                tangram[verx-j][very+i] = 'T';
                tangram[verx][very+i] = 'T';
                tangram[verx+j][very+i] = 'T';
                tangram[verx][very] = 't';
            }
        }
    } else if (rotate == 180)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j<=i; j++)
            {
                tangram[verx+i][very] = 'T';
                tangram[verx+i][very+j] = 'T';
                tangram[verx+i][very-j] = 'T';
                tangram[verx][very] = 't';
            }
        }
    } else if (rotate == 270)
    {
        for (i = 0; i < side; i++)
        {
            for (j = 0; j <= i; j++)
            {
                tangram[verx-j][very-i] = 'T';
                tangram[verx][very-i] = 'T';
                tangram[verx+j][very-i] = 'T';
                tangram[verx][very] = 't';
            }
        }
    }
    return;
}

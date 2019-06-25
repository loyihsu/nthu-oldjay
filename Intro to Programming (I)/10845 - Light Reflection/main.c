// Problem: http://140.114.86.238/problem/10845/
#include <stdio.h>

int main(void)
{
    int width, height;
    int i, j;
    int direction = 0;
    int count = 0;
    int num;
    
    //0 - upper-right
    //1 - lower-right
    //2 - upper-left
    //3 - lower-left
    
    scanf("%d%d", &width, &height);
    scanf("%d%d", &i, &j);
    scanf("%d", &num);
    
    while (count < num-1)
    {
        if (((i == 1)||(i == width))&&((j == 1)||(j == height)))
        {
            break;
        }
        
        if (direction == 0)
        {
            while (i > 1 && j < height)
            {
                i--;
                j++;
                if (i == 1)
                {
                    direction = 1;
                    count++;
                    break;
                } else if (j == height) {
                    direction = 2;
                    count++;
                    break;
                }
            }
        } else if (direction == 1) {
            while (i < width && j < height)
            {
                i++;
                j++;
                if (i == width)
                {
                    direction = 0;
                    count++;
                    break;
                } else if (j == height) {
                    direction = 3;
                    count++;
                    break;
                }
            }
        } else if (direction == 2) {
            while (i > 1 && j > 1)
            {
                i--;
                j--;
                if (i == 1)
                {
                    direction = 3;
                    count++;
                    break;
                } else if (j == 1) {
                    direction = 0;
                    count++;
                    break;
                }
            }
        } else if (direction == 3) {
            while (i < width && j > 1)
            {
                i++;
                j--;
                if (i == width)
                {
                    direction = 2;
                    count++;
                    break;
                } else if (j == 1)
                {
                    direction = 1;
                    count++;
                    break;
                }
            }
        }
    }
    
    
    printf("(%d,%d)", i, j);
    
    
    return 0;
}

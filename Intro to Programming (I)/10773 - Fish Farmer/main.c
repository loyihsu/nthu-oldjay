// Problem: http://140.114.86.238/problem/10773/
#include <stdio.h>
#include <string.h>

int main(void) {
    int noOfPondA = 0, noOfPondB = 0, years = 0, num;
    char pond[2];
    
    scanf("%d%d", &noOfPondA, &noOfPondB);
    scanf("%d", &years);
    while (years--) {
        scanf("%s%d", pond, &num);
        // If pond == "A", move num of fish to pond "B"
        noOfPondA = (!strcmp(pond,"A")) ? noOfPondA*(1.08)-num : noOfPondA*(1.08)+num;
        // If pond == "B", move num of fish to pond "A"
        noOfPondB = (!strcmp(pond,"B")) ? noOfPondB*(1.08)-num : noOfPondB*(1.08)+num;
    }
    printf("%d %d\n", noOfPondA, noOfPondB);
    
    return 0;
}

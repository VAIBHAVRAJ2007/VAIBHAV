#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int r = n%67;
    if(r == 0)
        printf("Divisible by 67\n");
    else
        printf("Not divisible by 67\n");
        printf("Reminder: %d\n", r);
    return 0;
}
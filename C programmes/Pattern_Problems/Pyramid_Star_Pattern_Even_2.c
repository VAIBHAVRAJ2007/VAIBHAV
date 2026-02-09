#include <stdio.h>

int main()
{
    int i, j, space,n;
    printf("Enter number of rows\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (space = 0; space < n-i-1; space++)
        {       
            printf(" ");
        }
        for (j = 0; j <  i+1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
        return 0;
}
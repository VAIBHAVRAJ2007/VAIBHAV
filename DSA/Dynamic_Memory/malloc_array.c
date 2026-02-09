#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, *x;
    printf("Enter size:");
    scanf("%d", &n);
    x = (int *)malloc(n * sizeof(int));
    if (x == NULL)
    {
        printf("No memory allocated.\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", x + i);
        // x[i]=i+1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", x[i]);
    }
    free(x);
    printf("\n");
    printf("%d\t", x[2]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, i, n;
    printf("Enter no. of elements:");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Insufficient memory");
        exit(1);
    }
    else
    {
        printf("Enter elements:");
        for (i = 0; i < n; i++)
            scanf("%d", (ptr + i));
    }
    printf("%d elements are:", n);
    for (i = 0; i < n; i++)
        printf("%d ", *(ptr + i));
    int choice, new;
    printf("\nIf you want to add more elements press 1, otherwise 0\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter no. of additional element:");
        scanf("%d", &new);
        int total = (new + n);
        ptr = (int *)realloc(ptr, total * sizeof(int));
        if (ptr == NULL)
        {
            printf("Insufficient memory");
            exit(1);
        }
        else
        {
            printf("Enter additional elements:");
            for (i = n; i < total; i++)
                scanf("%d", (ptr + i));
            printf("Updated array elements are:");
            for (i = 0; i < total; i++)
                printf("%d ", *(ptr + i));
        }
        free(ptr);
    }
    else
    {
        printf("Thank you");
        free(ptr);
    }
    return 0;
}
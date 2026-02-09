#include <stdio.h>
#include <stdlib.h>
void linear_search(int n, int search, int *arr)
{
    int k = 0;
    printf("Array elements are:");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }
    for (int i = 0; i < n; i++)
    {
        if (search == arr[i])
        {
            printf("\nElement found at %d", i + 1);
            k++;
            break;
        }
    }
    if (k == 0)
    {
        printf("\nElement not found.");
    }
}
int main()
{
    int n, search, *arr;
    printf("Enter number of elements:");
    scanf("%d", &n);
    arr = (int *)calloc(n, sizeof(int));
    printf("Enter %d elements:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    printf("Enter the element you want to search:");
    scanf("%d", &search);
    linear_search(n, search, arr);
    free(arr);
    return 0;
}
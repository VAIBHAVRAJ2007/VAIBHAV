#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, *arr, r, l = 0, search, m;
    printf("Enter no. of elements:");
    scanf("%d", &n);
    r = n - 1;
    arr = (int *)calloc(n, sizeof(int));
    printf("Enter elements in ascending order:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    printf("Enter element you want to search: ");
    scanf("%d", &search);
    while (l <= r)
    {
        m = (l + r) / 2;
        if (arr[m] == search)
        {
            printf("Element is found.");
            break;
        }
        else if (arr[m] > search)
        {
            r = m - 1;
        }
        else if (arr[m] < search)
        {
            l = m + 1;
        }
    }
    if (l > r)
    {
        printf("Element is not found.");
    }
    return 0;
}
#include <stdio.h>

int main()
{
    int a[50], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int pivot;
    scanf("%d",&pivot);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == pivot)
            printf("%d MATCHED",pivot);

    }
    return 0;
}
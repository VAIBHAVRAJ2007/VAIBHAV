#include <stdio.h>
int main()
{
    int n,temp,i,j;
    printf("Enter numbers of element in array\n");
    scanf("%d", &n);

    int a[n];
    printf("Enter elements in array:\n");
    for ( i = 0; i < n; i++)
        scanf("%d",&a[i]);

    printf("Before sorting array elements are:");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
        printf("\n");

    for ( i = 0; i < n - 1; i++)
    {
        for ( j = i + 1; j <= n - 1; j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("After sorting array elements are:");
    for ( i = 0; i < n; i++)
        printf("%d\t", a[i]);
        
        return 0;
}
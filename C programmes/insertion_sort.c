#include <stdio.h>
int main()
{
    int n,i,key,j;
    printf("Enter number of elements in array:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in array:\n");
    for ( i = 0; i < n;i++)
        {
		scanf("%d", &a[i]);
		}
    printf("Before sorting array become:");
    for (i = 0; i < n;i++)
		printf("%d ", a[i]);
    printf("\n");
    for (i = 1; i <= n - 1;i++)
    {
        key = a[i];
        j = i - 1;
        while(j>=0 && a[j]>key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    printf("After sorting array become:");
    for (i = 0; i < n;i++)
		printf("%d ", a[i]);
        return 0;
}

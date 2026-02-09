#include <stdio.h>
int main()
{
    int n,i,j,temp,a[100];
    printf("Enter numbers of element in array\n");
    scanf("%d", &n);
    a[n];
    printf("Enter elements in array:\n");
    for ( i = 0; i < n; i++)
        scanf("%d",&a[i]);
    printf("Before sorting elements of array are :\n");
    for ( i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    for (i = 1; i <= n - 1;i++){
        for (j = 0; j < n - i ; j++) {
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("After sorting elements of array are :\n");
    for ( i = 0; i < n; i++)
        printf("%d\t", a[i]);
        return 0;
}
#include<stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int LB,int UB)
{
    int j;
    int i = LB - 1;
    int pivot = a[UB];
    for (j = LB; j <= UB - 1;j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i + 1],&a[UB]);
    return (i + 1);
}
void quickSort(int a[], int LB, int UB)
{
    
    if (LB < UB)
    {
        int pos;
        pos = partition(a, LB, UB);
        quickSort(a, LB, pos - 1);
        quickSort(a, pos + 1, UB);
    }
}
void print_array(int a[],int  n)
{
    int i;
    for (i = 0; i <= n - 1; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
int main()
{
    int a[50],n,i;
    printf("Enter numbers of element in array :\n");
    scanf("%d", &n);
    printf("Enter elements in array :\n");
    for (i = 0; i <= n - 1; i++)
        scanf("%d",&a[i]);
    printf("Before Sorting array elements are:\n");
    print_array(a, n);
    quickSort(a, 0, n - 1);
    printf("After sorting array elements are:\n");
    print_array(a, n);
        return 0;
}
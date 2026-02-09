#include <stdio.h>
void merge(int a[], int mid, int low, int high)
{
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}
void print_array(int a[], int n)
{
    int i;
    for (i = 0; i <= n - 1; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
int main()
{
    int n, i;
    printf("Enter numbers of element in array A:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in array A:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Before Sorting array elements are:\n");
    print_array(a, n);
    mergeSort(a, 0, n - 1);
    printf("After sorting elements of array are :\n");
    print_array(a, n);
    return 0;
}
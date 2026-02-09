#include <stdio.h>
void selection_sort(int[], int);
void print_array(int[], int);
int main()
{
    int a[100], n, i;
    printf("Enter numbers of element in array: ");
    scanf("%d", &n);
    printf("Enter elements in array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    print_array(a, n);
    selection_sort(a, n);
    print_array(a, n);
    return 0;
}
void print_array(int b[], int n)
{
    int i;
    printf("Array elements are: ");
    for (i = 0; i < n; i++)
        printf("\t%d", b[i]);
    printf("\n");
}
void selection_sort(int b[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (b[i] > b[j])
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    printf("After sorting:\n");
}
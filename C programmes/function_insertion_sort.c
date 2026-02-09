#include <stdio.h>
void printarray(int b[],int n)
{
    int i;
    printf("Array elements are: ");
    for (i = 0; i < n; i++)
        printf("\t%d", b[i]);
    printf("\n");
}
void insertion_sort(int b[],int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key)
        {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}
int main()
{
    int n ,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int b[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    printarray(b, n);
    insertion_sort(b, n);
    printarray(b, n);
    return 0;
}
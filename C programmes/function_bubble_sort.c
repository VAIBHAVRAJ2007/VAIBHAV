#include<stdio.h>
void print_array(int [], int );
void bubble_sort(int [], int);

int main(){
    int n, i;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements in array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    print_array(a,n);
    bubble_sort(a,n);
    print_array(a,n);
    return 0;
}
void print_array(int b[],int n)
{
    int i;
    printf("Array elements are: ");
    for (i = 0; i < n; i++)
        printf("%d\t", b[i]);
    printf("\n");
}
void bubble_sort(int b[],int n)
{
    int p,c,temp;
    for (p = 0; p <= n - 1; p++)
    {
        for (c = 0; c < n - p ;c++)
        {
            if(b[c]>b[c+1]){
                temp = b[c];
                b[c] = b[c+1];
                b[c+1] = temp;
            }
        }
    }
}
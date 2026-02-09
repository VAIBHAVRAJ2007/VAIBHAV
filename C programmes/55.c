#include<stdio.h>
void printEven(int);
void printEven(int x)
{
	
	if (x % 2 == 0)
		printf("%d\t", x);
}
int main()
{
    int n,i;
    int a[n];
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    printf("Array elements are:");
    for ( i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for ( i = 0; i < n; i++)
        printEven(a[i]);
    return 0;
}
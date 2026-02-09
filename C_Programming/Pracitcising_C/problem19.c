//Write a program to calculate the factorial of a given number using a for loop
#include <stdio.h>

int main()
{
    int n,i,fact=1;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        fact*=i;
    }
    printf("%d",fact);
    return 0;
}
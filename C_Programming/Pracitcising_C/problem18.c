//Write a program to calculate the sum of the numbers occurring in the multiplication table of 8.
#include <stdio.h>

int main()
{
    int i,n=8,a,sum=0;
    for(i=1;i<=10;i++)
    {
        a=n*i;
        sum+=a;
        printf("%d\n",a);
    }
    printf("%d",sum);
    return 0;
}
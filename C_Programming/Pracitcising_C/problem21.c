//Write a program to check whether a given number is prime or composite using for loop.
#include <stdio.h>

int main()
{
    int i,n;
    printf("Enter a number:");
    scanf("%d",&n);
    if(n==1)
    {
        printf("1 is not a prime number");
    }
    else if (n==0)
    {
        printf("0 is not a prime number");
    }
    else
    {
    for(i=n-1;i>=2;i--)
    {
        
        if(n%i==0)
         break;
    }
    if(i!=1)
    printf("%d is composite number",n);
    else
     printf("%d is a prime number",n);
    }
        return 0;
}   
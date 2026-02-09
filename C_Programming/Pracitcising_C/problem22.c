//Write a program to check whether a given number is prime or not using while loop.
#include <stdio.h>

int main()
{
    int i,n;
    printf("Enter a number:");
    scanf("%d",&n);
    i=n-1;
    while(i>=2)
    {
        
        if(n%i==0)
        {
         break;}
         i--;
    }
    if(i!=1)
    printf("%d is not a prime number",n);
    else
    printf("%d is a prime number",n);
    return 0;
}   
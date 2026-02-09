// factorial of a number  using while loop
#include <stdio.h>

int main()

{
    int n, i, fact=1;
    printf("Enter a number to calculate its factorial:");
    scanf("%d",&n);
    i=n;
    while(i>=1)
    {
        fact=fact*i;
        i--;
    }
    printf("factorial of %d=%d",n,fact);
    return 0;
}
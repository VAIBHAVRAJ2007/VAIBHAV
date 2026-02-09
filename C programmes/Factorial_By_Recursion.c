#include <stdio.h>
int fact(unsigned  int);

int main()
{
    int n, r;
    printf("Enter a number\n");
    scanf("%d", &n);

    if(n==0)
        printf("Factorial of 0 = 1");

    else
    {
        r = fact(n);
        printf("Factorial of %d = %u", n, r);
    }
    return 0;
}
int fact(unsigned int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
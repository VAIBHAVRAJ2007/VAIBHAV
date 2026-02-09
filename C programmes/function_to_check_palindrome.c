#include <stdio.h>
void palindrome(int,int);
int main()
{
    int n,org,rem,rev=0;
    printf("Enter a number:");
    scanf("%d", &n);
    org = n;
    while(n!=0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    printf("Reverse=%d\n",rev);
    palindrome(org,rev);
    return 0;
}
    void palindrome(int num,int reverse)
    {
        if(num==reverse)
            printf("Palindrome\n");
        else
            printf("Not palindrome\n");
    }
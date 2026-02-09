#include <stdio.h>
int main()
{
    int a = 1245,rem,rev=0;
    while(a!=0)
    {
        rem = a % 10;
        rev = rev * 10 + rem;
        a = a / 10;
    }
    printf("%d", rev);
    return 0;
}
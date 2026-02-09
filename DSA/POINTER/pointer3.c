#include <stdio.h>
int main()
{
    int a = 5, *x = &a;
    // printf("Value of a = %d\n", a);
    // printf("Value of a = %d\n", *x);
    // printf("Value of address of a = %u\n", &a);
    // printf("Value of address of a = %u\n", x);
   int p= *--x;
    printf("Value of a = %d\n", a);
    printf("Value of a = %u\n", p);
    printf("Value of address of a = %u\n", &a);
    printf("Value of address of a = %u\n", x);
    return 0;
}
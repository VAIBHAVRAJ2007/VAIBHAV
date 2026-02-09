#include <stdio.h>
struct Test
{
    char c;
    int a;
    float b;
}t3,t4;
int main()
{
    struct Test t1,t2;
    // scanf("%d", &t1.a);
    // scanf("%d", &t2.a);
    // scanf("%g", &t1.b);
    // scanf(" %c", &t1.ch);
    // printf(" %c", t1.ch);
    // scanf(" %c", &t2.ch);
    // printf(" %c", t2.ch);
    // printf("%d %d %g", t1.a,t2.a,t1.b);
    printf("%u", sizeof(t3));
    return 0;
}
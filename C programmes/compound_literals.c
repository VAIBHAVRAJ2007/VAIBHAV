#include <stdio.h>
typedef struct Test
{
    int a;
    float b;
}demo;
demo hello(demo t1)
{
    demo t3 = t1;
     t3.b = t3.b + 1;
    printf("%g ", t3.b);
    t1.a = t1.a + 10;
    return t1;
}
int main()
{
    demo t2 = hello((demo){5,5.5});
    printf("%d", t2.a);
    return 0;
}
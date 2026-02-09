#include <stdio.h>

int main()
{
    int x = 3;
    int y = 8;
    int *a = &x;
    // char *p;
    // p = &x;
    // printf("%d ", x);
    // printf("%d ", *p);
    // printf("%d ", *(p+0));
    // printf("%d ", p[0]);
    printf("%p ",&x);
    printf("%p",&a);
    return 0;
}
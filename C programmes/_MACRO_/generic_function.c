#include <stdio.h>
#define MAX(FNAME, DTYPE) \
DTYPE FNAME(DTYPE x,DTYPE y) \
{                               \
    return x > y ? x : y;           \
}                                       

MAX(int_max, int)
MAX(float_max, float)
MAX(long_max, long)

int main()
{
    int p;
    float q;
    long r;
    p = int_max(5, 9);
    q = float_max(15.7f, 98.5400f);
    r = long_max(56845846L, 984455956L);
    printf("largest integer = %d\n", p);
    printf("largest float = %f\n", q);
    printf("largest long  = %ld\n", r);
    return 0;
}
#include <stdio.h>

int main()
{
    int x = 11,
    y = 10;
    x > y ? ++y : ++x;
    printf("%d", x + y);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr = malloc(10*4);
    scanf("%d", *ptr);
    printf("%d", *ptr);
    return 0;
}
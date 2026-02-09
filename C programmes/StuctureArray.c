#include <stdio.h>
typedef struct Test
{
    int a;
    float b;
}array;
int main()
{
    array arr[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &arr[i].a);
        scanf("%f", &arr[i].b);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i].a);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%f ", arr[i].b);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d %f ", arr[i].a,arr[i].b);
    }
    return 0;
}
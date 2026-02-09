#include<stdio.h>
int main()
{
    int x;
    printf("enter x:");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:printf("it is an odd number\n");break;

    default:
        printf("invalid input\n");


    }
    return 0;

}

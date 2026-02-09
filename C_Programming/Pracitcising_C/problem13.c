#include <stdio.h>

int main()
{
    int a,b,c,d;
    printf("Enter a,b,cand d:");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a>b && a>c && a>d)
    {
        printf("\na is the largest number\n");
        printf("\na is %d\n",a);
    }
    else if(b>a && b>c && b>d)
    {
        printf("\nb is the largest number\n");
        printf("\nb is %d\n",b);
    }
    else if(c>a && c>b && c>d)
    {
        printf("\nc is the largest number\n");
        printf("\nc is %d\n",c);
    }
    else
    {
        printf("\nd is the largest number\n");
        printf("\nd is %d\n",d);
    }
    return 0;
}
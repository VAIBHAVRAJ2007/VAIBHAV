#include<stdio.h>
int main()
{
    int a[]={5,85,45,78,55},*p,i;
    p=&a[0];
    for( i=0;i<5;i++)
   {// {printf("%d\t",a[i])
        printf("%d\t",*p++);
    }


    return 0;
}

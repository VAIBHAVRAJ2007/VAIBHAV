#include<stdio.h>
int main()
{
    int i, s=0;
    for(i=1; i<=10; i++)
    {
    	s+=i;
    }
    printf("sum of given series\n");
    printf("%d",s);
    return 0;
}

#include<stdio.h>
int main()
{
    int i,n;
    long int p=1;
    printf("enter any positive number\n");
    scanf("%d",&n);
    if(n==0)
    {
        printf("factorial of 0 is 1\n");
    }
    else
    {
      for(i=1;  i<=n;  i++)
      {
          p=p*i;
      }
      printf("factorial of %d = %ld",n,p);
    }
    return 0;
}


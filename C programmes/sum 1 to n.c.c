#include<stdio.h>
int main()
{
	int i,s=0,n;
	printf("enter a natural number\n");
   scanf("%d",&n);

	for(i=1;i<=n;i=i+1)
	{
		s=s+i;
	}

	printf("sum of all natural number from 1 to %d is %d\n",n,s);
    
	return 0;

}


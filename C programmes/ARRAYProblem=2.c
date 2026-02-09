#include<stdio.h>
int main()
{
	int a[50],i,product=1;
	for(i=0;i<=5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<=5;i++)
	{
		product=product*a[i];
		
		
	}
	printf("%d",product);
	return 0;
}

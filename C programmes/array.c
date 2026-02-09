#include<stdio.h>
int main()
{
	int a[50],i,n,sindx,lindx,small,large;
	printf("how many elements are in array\n");
	scanf("%d",&n);
	printf("enter elements in array\n");
	for(i=0; i<=n-1;i++)
	{scanf("%d",&a[i]);}
	for(i=0; i<=n-1;i++)
	{
		if(a[i]<small)
		{
			small=a[i];
			sindx=i;
		}
		if(a[i]>large)
		{
			large=a[i];
			lindx=i;
		}
	}
	a[sindx]=large;
	a[lindx]=small;
	printf("array elements are\n");
	for(i=0; i<=n-1;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}

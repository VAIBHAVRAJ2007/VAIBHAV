#include<stdio.h>
int main()
{
	int a[50],i,n,LB,UB,LPOS,LLPOS,RLPOS,LL,RL,SL,SLPOS;
	printf("how many elements are in array\n");
	scanf("%d",&n);
	printf("enter elements in array\n");
	for(i=0; i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	LB=0;
	UB=LPOS-i;
	for(i=LB;i<=UB;i++)
	{
		LL=a[i];
		LLPOS=i;
	}
	LB=LPOS+1;
	UB=n-1;
	for(i=LB;i<=UB;i++)
	{
		RL=a[i];
		RLPOS=i;
	}
	SL=LB;
	SLPOS=i;
	printf("second largest number is\n ");
	printf("%d",SL);
	return 0;
}


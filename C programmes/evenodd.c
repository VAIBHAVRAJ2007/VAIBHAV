#include<stdio.h>
int main()
{
	int num,r;
	printf("enter a number");
	scanf("%d",&num);
	r=num%2;
	if(r==0)
	{
		printf("number is even\n");
	}
	else
	{
		printf("number is odd\n");
	}
	printf("number=%d",num);
	return 0;
}

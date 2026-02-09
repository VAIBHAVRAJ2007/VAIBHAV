#include<stdio.h>
int main()
{
	int num,count=0;
	printf("Enter an integer number\n ");
	scanf("%d",&num);
	do
	{
		num=num/10;
		count++;
	}
	while(num != 0);
	printf("number of digit =%d",count);
}

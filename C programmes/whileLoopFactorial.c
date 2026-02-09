#include<stdio.h>
int main()
{
	int n,i=1;
	long long int p=1;
	printf("Enter an integer number=");
	scanf("%d",&n);
	if(n==0)
	{
		printf("Factorial of 0 is 1\n");
	}
	else
	{
		while(i <= n)
	{
		p= p*i;
		i++;
	}
	printf("Factorial of %d=%lld",n,p);
	}
	return 0;

}


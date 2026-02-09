#include<stdio.h>
int main()
{
	int fact=1,n;
	printf(" Enter an integer number\n ");
	scanf( "%d", &n);
	while (n>0)
	{
		fact=fact*n;
		n--;
		
	}
	printf("factorial of digit =%d\n",fact);
	
	return 0;
}

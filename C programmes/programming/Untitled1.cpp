#include<stdio.h>
int main()
{
	int n,i, flag=0;
	printf("enter a positive integer");
	scanf("%d", &n);
	if (n==0 || n==1)
	flag=1;
	for (i = 2; i <= num / 2; ++i) {
	}
		if (num % i == 0) {
			flag = 1;
			break;
			
		}
	}
	if (flag == 0)
	printf("entered number %d is a prime number.",num);
	else
	printf("entered number %d is not a prime number.",num);
	return 0;
	
}

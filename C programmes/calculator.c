#include<stdio.h>

int main()
{
	int x,y;

	char op;
	printf("enter two integer value\n");
	scanf("%d%d",&x,&y);

	printf("choose any one operator('+','-','*','/','%')\n");
	scanf(" %c",&op);

	switch(op)
	{
		case'+':printf("sum of x+y=%d",x+y);break;

		case'-':printf("difference of x-y=%d",x-y);break;

		case'*':printf("product of x*y=%d",x*y);break;

		case'/':printf("quotient of x/y=%d",x/y);break;

		case'%':printf("remainder of x%y=%d",x%y);break;

		default:
			printf("invalid operator\n");
    }

	   return 0;
}

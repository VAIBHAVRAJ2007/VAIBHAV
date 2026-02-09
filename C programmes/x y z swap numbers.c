#include<stdio.h>
int main()
{
	int x;
	int y;
	int z;
	printf("enter two numbers:\n");
	scanf("%d%d", &x, &y);
	
	printf("before swapping\n");
	printf("x= %d,y=%d",x,y);
	z=x;
	x=y;
	y=z; 
	printf("\nafter swapping\n");
	printf("x=%d,y=%d",x,y);
	return 0;
}

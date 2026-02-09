#include<stdio.h>
int main()
{

	int a;
	char b;
	
	printf("Enter ASCII code:");
	scanf("%d",&a);
	printf("character value of %d = %c\n",a,a);
	
	getchar();
	printf("Enter character\n");
	scanf("%c",&b);
	printf("ASCII code for %c\n = %d",b,b);
	
	return 0;
}


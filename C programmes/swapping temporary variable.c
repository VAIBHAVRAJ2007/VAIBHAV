#include<stdio.h>
int main()
{
	int var1, var2, temp;
	printf("enter two integers\n");
	scanf("%d%d", &var1, &var2);
	printf("before swappingn");
	printf("var1 = %d\nvar2 = %d\n",var1, var2);
	temp = var1;
	var1 = var2;
	var2 = temp;
	printf("after swappingn");
	printf("var1 = %d\nvar2 = %d\n",var1, var2);
	return 0;
}

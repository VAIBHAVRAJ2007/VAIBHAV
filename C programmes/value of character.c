#include<stdio.h>

main()
{
	char c;
	printf("enter a character:");
	scanf("%c", &c);
	printf("ASCII value = %d",c);

{
    int a,b,s;
    printf("enter a:");
    scanf("%d",&a);

    printf("enter b:");
    scanf("%d",&b);
    s=a+b;
    printf("the sum of %d and %d is %d\n",a,b,s);
    return 0;
}

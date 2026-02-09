#include<stdio.h>
int main()
{
	int i,s=0;
	for(i=1;i<=20;i=++i)
	{
		s=s+i;
	}
	  
	printf("sum of all number b/w (1 to 20)=%d",s);
	  
	return 0;
	  
}

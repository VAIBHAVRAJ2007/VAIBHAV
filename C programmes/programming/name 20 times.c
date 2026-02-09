#include<stdio.h>
int main()
{
	int i,s=0;
	for(i=200;i>=1;i=--i)
	{
		s=s+i;
	}
	  
	printf("sum of all number (20 to 1)=%d",s);
	  
	return 0;
	  
}

#include<stdio.h>
int main()
{
	int size=90,marks[size],i;
	for(i=0;i<=9;i++)
	{
		int a=i+1;
		printf("Marks obtained by Roll No %d = ",a);
		scanf("%d",&marks[i]);
	}
	for(i=0;i<=9;i++)
    {
	if(marks[i]<50)
	{
		int a=i+1;
	printf("Roll No = %d\n",a);
    }		
   }	
	return 0;
	
}

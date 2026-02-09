#include<stdio.h>
int main()

{
	int arr[5],i;
	for(i=0;i<5;i++)
        {
    	int a=i+1;
	printf("enter element %d ",a);
	scanf("%d",&arr[i]);
}
	
	for(i=5;i>0;i--)
		{
	printf("%d  ",arr[i]);
}                                           
	
	
	return 0;
}

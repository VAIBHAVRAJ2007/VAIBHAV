#include<stdio.h>
int main()
{
	int M[50][50],c,r,i,j;
	printf("Enter order of matrix M\a\n");
	scanf("%d%d",&r,&c);
	printf("Enter elements in matrix M\n");
    for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&M[i][j]);
		}
	}
	printf("Given Matrix M:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",M[i][j]);

		}
		printf("\n");
	}


	return 0;
}


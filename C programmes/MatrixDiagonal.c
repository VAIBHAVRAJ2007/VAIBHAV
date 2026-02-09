#include<stdio.h>
int main(){
	int A[50][50],m,n,i,j;

			printf("Enter order of a matrix A\a\n");
			scanf("%d%d",&m,&n);

			printf("Enter elements in matrix A\n");
    for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}
			printf("Original matrix A:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%d\t",A[i][j]);

		}
			printf("\n");
	}
	printf("\n");
	printf("Diagonal elements of matrix A are:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				printf("%d\t",A[i][j]);
			}
				else
				{
					printf("0\t");
				}

		}
				printf("\n");
	}


	return 0;
}


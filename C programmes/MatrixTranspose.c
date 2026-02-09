#include<stdio.h>
int main(){
	int A[50][50],i,j,r,c,m,n;

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
			printf("Transpose of A:\n");
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					printf("%d\t",A[j][i]);
				}
				printf("\n");
			}
	return 0;
}


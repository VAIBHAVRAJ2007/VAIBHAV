#include<stdio.h>
int main(){
	int M[50][50],N[50][50],O[50][50];
	int c,r,i,j,k,l,p,q;
			printf("Enter order of matrices (M and N)\a\n");
			scanf("%d%d",&r,&c);

			printf("Enter elements in matrix M\n");
    for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf("%d",&M[i][j]);
		}
	}
			printf("Original matrix M:\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d\t",M[i][j]);

		}
			printf("\n");
	}
			printf("Enter elements in matrix N\n");
    for(k=0;k<r;k++){
		for(l=0;l<c;l++){
			scanf("%d",&N[k][l]);
		}
	}
			printf("Original matrix N:\n");
	for(k=0;k<r;k++){
		for(l=0;l<c;l++){
			printf("%d\t",N[k][l]);
		}
			printf("\n");
	}
			printf("Updated matrix O:\n");
	for(p=0;p<r;p++){
		for(q=0;q<c;q++){
			O[p][q]=M[p][q]+N[p][q];
			printf("%d\t",O[p][q]);
		}
			printf("\n");
	}

	return 0;
}

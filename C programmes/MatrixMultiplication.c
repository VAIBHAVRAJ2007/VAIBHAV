#include <stdio.h>
int main()
{

	int A[50][50], B[50][50], C[50][50];
	int m, n, p, q, i, j, k, l, c, r, h;

	printf("Enter order of matrix A\a\n");
	scanf("%d%d", &m, &n);

	printf("Enter order of matrix B\a\n");
	scanf("%d%d", &p, &q);

	if (n != p)
	{
		printf("Matrix multiplication not possible\n");
		printf("Columns of A must equal rows of B\n");
		return 0;
	}

	printf("Enter elements in matrix A\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	printf("Original matrix A:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}

	printf("Enter elements in matrix B\n");
	for (k = 0; k < p; k++)
	{
		for (l = 0; l < q; l++)
		{
			scanf("%d", &B[k][l]);
		}
	}

	printf("Original matrix B:\n");
	for (k = 0; k < p; k++)
	{
		for (l = 0; l < q; l++)
		{
			printf("%d\t", B[k][l]);
		}
		printf("\n");
	}

	printf("After multiplication, matrix 'C':\n");
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < q; c++)
		{
			C[r][c] = 0;
			for (h = 0; h < n; h++)
			{
				C[r][c] += A[r][h] * B[h][c];
			}
			printf("%d\t", C[r][c]);
		}
		printf("\n");
	}

	return 0;
}

#include<stdio.h>
void fibonacci(int);
int main()
{
    int n;
    printf("enter number of elen=ments:\n");
    scanf("%d", &n);
    fibonacci(n);
    return 0;
}
void fibonacci(int num)
{
    int n1 = 0, n2 = 1, n3, count;
    printf("fibonacci series:\n");
    printf("%d\t%d\t", n1, n2);
    for (count = 3; count <= num;count++)
    {
        n3 = n1 + n2;
        printf("%d\t", n3);
        n1 = n2;
        n2 = n3;
    }
}

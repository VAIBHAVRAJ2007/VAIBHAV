#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr, i, n;
    printf("Enter no. of elements:");
    scanf("%d", &n);
    ptr = (int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Insufficient memory");
        exit(1);
    }
    else{
        printf("Enter elements:");
        for(i = 0; i < n;i++)
            scanf("%d",(ptr + i));
    }
    printf("Odd elements are:");
    for(i = 0; i < n;i++){
        if(*(ptr+i)%2!=0)
            {
            printf("%d ", *(ptr + i));
        }
    }
    free(ptr);
    return 0;
}

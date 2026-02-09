#include <stdio.h>
#include<stdlib.h>
void bubble_sort(int *ptr,int n)
{
    for (int c = 0; c < n-1;c++)
        {
              for (int p = 0; p < n - c-1; p++)

            {
                if(*(ptr+p)>*(ptr+p+1))
                {
                    int temp = *(ptr + p);
                    *(ptr + p) = *(ptr + p + 1);
                    *(ptr + p + 1) = temp;
                }
            }
        }
}
int main(){
    int n, i, *ptr;
    printf("Enter number of elements:");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if(ptr==NULL){
        printf("Insufficient memory");
        exit(1);
    }
    else{
        printf("Enter elements:");
        for (i = 0; i < n;i++)
            scanf("%d", (ptr + i));
        printf("\n");
        printf("Elements are:");
        for (i = 0; i < n;i++) 
            printf("%d ", *(ptr + i));
        bubble_sort(ptr, n);
    }
        printf("\nSorted Elements are (before additional elements):");
        for (i = 0; i < n;i++)
            printf("%d ", *(ptr + i));
        printf("\n");


        int choice, new;
        printf("\nIf you want to add more elements press 1, otherwise 0\n");
        scanf("%d", &choice);
        if (choice == 1){
        
            printf("Enter no. of additional element:");
            scanf("%d", &new);
            int total = (new + n);
            ptr = (int *)realloc(ptr, total * sizeof(int));
            if (ptr == NULL)
            {
                printf("Insufficient memory");
                exit(1);
            }
            else
            {
                printf("Enter additional elements:");
                for (i = n; i < total; i++)
                    scanf("%d", (ptr + i));
                printf("\nTotal elements before sorting:");
                for (i = 0; i < total;i++)
                    printf("%d ", *(ptr + i));
                    bubble_sort(ptr, total);

         printf("\nUpdated array elements are:");
                for (i = 0; i < total; i++)
                    printf("%d ", *(ptr + i));
    }
    free(ptr);
            }
        else{
            printf("Thank you");
            free(ptr);
        }
    return 0;
}
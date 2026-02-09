#include <stdio.h>
#include<stdlib.h>
struct student{
    int rn;
    float sgpa;
};
int main()
{
    int i, n;
    struct student *ptr;
    printf("\nEnter no. of students:");
    scanf("%d", &n);
    ptr = (struct student *)malloc(n * sizeof(struct student));
    printf("\nEnter roll no and sgpa:");
    for (i = 0; i < n;i++){
        printf("\nRoll No. :");
        scanf("%d", &(ptr+i)->rn);
        printf("\nSGPA :");
        scanf("%f", &(ptr+i)->sgpa);
    }
    printf("\nSaved records:");
    printf("\nRoll N0.\t SGPA\n");
    for (i = 0; i < n;i++)
        printf("%d\t %f\n", (ptr+i)->rn, (ptr+i)->sgpa);
        return 0;
}
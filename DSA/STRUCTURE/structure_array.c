#include <stdio.h>
struct student{
    int rn;
    float sgpa;
};
int main()
{
    int i, n;
    struct student std[100];
    printf("\nEnter no. of students:");
    scanf("%d", &n);
    printf("\nEnter roll no and sgpa:");
    for (i = 0; i < n;i++){
        printf("\nRoll No. :");
        scanf("%d", &std[i].rn);
        printf("\nSGPA :");
        scanf("%f", &std[i].sgpa);
    }
    printf("\nSaved records:");
    printf("\nRoll N0.\t SGPA\n");
    for (i = 0; i < n;i++)
        printf("%d\t     %f\n", std[i].rn, std[i].sgpa);
        return 0;
}
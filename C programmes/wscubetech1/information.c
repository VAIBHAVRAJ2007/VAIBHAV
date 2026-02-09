#include<stdio.h>
#include<string.h>
struct student{
    int rn;
    char name[50];
    float inter;
    char gen;
};
int main(){
    struct student s1, s3;
    s1.rn = 69;
    s1.inter = 78.13;
    strcpy(s1.name, "Vaibhav raj");
    s1.gen = 'M';
    printf("Enter details of student 3->\n");
    printf("Name:\n");
    gets(s3.name);
    printf("Roll No.\n");
    scanf("%d", &s3.rn);
    printf("Inter Percentage:\n");
    scanf("%f", &s3.inter);
    printf("Gender:\n");
    scanf("%c", &s3.gen);
    printf("\n");
    
    printf("Details of student 1->\n");
    printf("Name = %s\n", s1.name);
    printf("Roll No. = %d\n", s1.rn);
    printf("Inter percentage = %g\n", s1.inter);
    printf("Gender = %c\n", s1.gen);
    printf("\n");

    struct student s2={12345,"ram kumar",89.68,'m'};
    printf("Details of student 2->\n");
    printf("Name  = %s\n", s2.name);
    printf("Roll No.  = %d\n", s2.rn);
    printf("Inter percentage  = %g\n", s2.inter);
    printf("Gender  = %c\n", s2.gen);
    printf("\n");

    printf("Details of student 3->\n");
    printf("Name = %s\n", s3.name);
    printf("Roll No. = %d\n", s3.rn);
    printf("Inter percentage  = %g\n", s3.inter);
    printf("Gender = %c\n", s3.gen);

    return 0;
}

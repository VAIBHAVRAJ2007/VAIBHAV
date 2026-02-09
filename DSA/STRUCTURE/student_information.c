#include<stdio.h>
#include<string.h>
struct date{
    int dd, mm, yy;
};
struct student{
    int rn;
    char name[50];
    float inter;
    char gen;
    struct date dob;
}s1;
int main(){
    struct student s3, s2 = {12345, "ram kumar", 89.68, 'm',{11,01,2005}};
    //student 1 details
    s1.rn = 12469;
    s1.inter = 78.13;
    strcpy(s1.name, "vaibhav raj");
    s1.gen = 'M';
    s1.dob.dd = 21;
    s1.dob.mm = 01;
    s1.dob.yy = 2007;
    //input for student 3
    printf("Enter details of student 3->\n");
    printf("Name:\n");
    gets(s3.name);

    printf("Roll No.\n");
    scanf("%d", &s3.rn);

    printf("Inter Percentage:\n");
    scanf("%f", &s3.inter);

    printf("Gender:\n");
    scanf(" %c", &s3.gen);
    printf("Enter DOB (dd mm yy):\n");
    scanf("%d %d %d", &s3.dob.dd, &s3.dob.mm, &s3.dob.yy);
    printf("\n");
    //output for student 1
    printf("Details of student 1->\n");
    printf("Name = %s\n", s1.name);
    printf("Roll No. = %d\n", s1.rn);
    printf("Inter percentage = %g\n", s1.inter);
    printf("Gender = %c\n", s1.gen);
    printf("DOB = %02d/%02d/%04d\n", s1.dob.dd,s1.dob.mm,s1.dob.yy);
    printf("\n");
    //output for student 2
    printf("Details of student 2->\n");
    printf("Name  = %s\n", s2.name);
    printf("Roll No.  = %d\n", s2.rn);
    printf("Inter percentage  = %g\n", s2.inter);
    printf("Gender = %c\n", s2.gen);
    printf("DOB = %d/%d/%d\n", s2.dob.dd,s2.dob.mm,s2.dob.yy);
    printf("\n");
    //output for student 3
    printf("Details of student 3->\n");
    printf("Name = %s\n", s3.name);
    printf("Roll No. = %d\n", s3.rn);
    printf("Inter percentage  = %g\n", s3.inter);
    printf("Gender = %c\n", s3.gen);
    printf("DOB = %d/%d/%d\n", s3.dob.dd, s3.dob.mm, s3.dob.yy);

    return 0;
}
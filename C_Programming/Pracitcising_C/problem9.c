/*Write a program to determine whether a student has passed or failed.
To pass, a student requires a total of 40% and at least 33% in each subject. 
Assume there are three subjects and take the marks as input from the user.*/
#include <stdio.h>

int main()
{
    int sub1,sub2,sub3,total;
    
    printf("Enter the marks of three subjects(out of 100):");
    scanf("%d%d%d",&sub1,&sub2,&sub3);
    total=sub1+sub2+sub3;
    float a=((sub1+sub2+sub3)*100/300);
    // if(sub1*100/250>=65 && sub2*100/250>=65 && sub3*100/250>=65 && (sub1+sub2+sub3)*100/750>=53)
    //     printf("The student has passed the exam.\n");
    // else
    //     printf("The student has failed the exam.\n");
    if(sub1*100/100<=33 || sub2*100/100<=33 || sub3*100/100<=33){
        printf("The student has failed the exam due to lesser individuals marks.\n");
        printf("%d\n\n",total);
        printf("%f\n",a);}
    else if(  a<=40){
        printf("The student has failed the exam due to lesser total percentage.\n");
        printf("%d\n",total);
        printf("%f\n",a);}
    else{
        printf("The student has passed the exam.\n");
        printf("%d\n",total);
        printf("%f\n",a);}
    return 0;
}
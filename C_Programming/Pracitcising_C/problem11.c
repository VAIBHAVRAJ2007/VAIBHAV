/*Write a program to find whether a year entered by the user is a leap year or not. 
Take year as an input from the user.*/
#include <stdio.h>

int main()
{
    int year;
    printf("Enter year:");
    scanf("%d",&year);
    if(year%4==0  || year%400==0)
    printf("Leap year\n");
    else
    printf("Not a leap year\n");
    return 0;
}
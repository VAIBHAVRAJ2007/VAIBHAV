// Write a program to print multiplication table of a given number n.
#include <stdio.h> //header file for standard input output

int main() //main function 
{
    int i,n,a; //declaring variables i,n,a 
    printf("Enter the number: "); //taking input from user 
    scanf("%d", &n); //storing the input in n 
    for ( i = 1; i <=10; i++) //for loop to print the multiplication table of the number 
    {
        a = n*i; //multiplying the number with i 
        printf("%d x %d = %d\n",n,i,a); //printing the multiplication table 
    }
    return 0; //returning 0 to end the program 
}
//Write a program to print multiplication table of a number n in reversed order

#include <stdio.h> // include the header file stdio.h

int main() // main function
{
    int i,n,a; // i is the counter, n is the number to be multiplied, a is the result of the multiplication
    printf("Enter a number:"); // ask the user to enter a number
    scanf("%d",&n); // store it in the variable n
    for(i=10;i>=1;i--) // loop to multiply the number with 10 to 1
    {
        a=n*i; // multiply the number with the counter
        printf("%d x %d = %d\n",n,i,a); // print the result
    }

    return 0;
}
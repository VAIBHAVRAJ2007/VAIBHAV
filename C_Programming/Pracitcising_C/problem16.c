//Write a program to sum first ten natural numbers using while loop.

#include <stdio.h> //header file for input output functions 

int main()  //main function body start 
{
    int sum=0,i=1;//variable declaration and initialization 
    while( i<=10)//while loop start
    {
        sum +=i;//sum of first 10 natural number 
        i++; //increment i // i=i+1 // i+=1
    }
    printf("sum of first 10 natural number = %d",sum); //print the sum of first 10 natural number
    return 0; //return statement 
}
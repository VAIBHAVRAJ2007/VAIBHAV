#include<stdio.h> // include stdio.h library file before compilation of this program
int main() // main function is called by OS (operating system) when we run the program
{ // start of main function
	int i,s=0,n; // i is loop variable, s is sum of all number b/w (1 to n), n is number of iteration

	printf("Enter the number :"); // ask user to enter the number
	scanf("%d",&n); // take input from user and store it in variable n

	for(i=1;i<=n;i++) // loop will run from 1 to n 
	{
		s=s+i; // sum of all number b/w (1 to n) will be stored in s variable
	}

	printf("sum of all number b/w (1 to %d)=%d",n,s); // print the sum of all number b/w (1 to n) on screen
    
	return 0; // return 0 to OS (operating system) means success
} // end of main function

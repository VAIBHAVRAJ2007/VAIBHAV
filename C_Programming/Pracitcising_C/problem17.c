// Write a program to sum first ten natural numbers using ‘for’  loop. 
#include <stdio.h>

int main()
{
    int sum=0,i=1;
    /*for(i=1;i<=10;i++)
    {
        sum+=i;
    }
    printf("sum of first 10 natural number = %d\n",sum);*/

    //using do 'while' loop
    do
    {
         sum+=i;
         i++;
    } while (i<=10);
    printf("sum of first 10 natural number = %d\n",sum);
    return 0;
}
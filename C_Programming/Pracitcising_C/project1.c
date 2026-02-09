#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    
    if(n>7)
    {
        printf("Lower number please");
    }
    else if(n<7) 
    {
        printf("Higher number please");
    }
    else
    {
        printf("You guessed it right");
    }
    
    return 0;
}
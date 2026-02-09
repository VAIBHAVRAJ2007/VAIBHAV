#include <stdio.h>
#define PRINT_1 printf("Enter a number:");
#define SCAN scanf("%d", &num);
#define DIV(n,i) (n % i == 0)
#define PRINT_COMP printf("COMPOSITE NUMBER");
#define PRINT_PRIME printf("PRIME NUMBER");
#define START int main(){
#define END return 0; }
START
    int num,i;
    PRINT_1;
    SCAN;
    for (i = num-1; i >= 2; i--)
    {
        if(DIV(num,i))
        {
            PRINT_COMP;
            break;
        }
    }
    if(i==1)
    {
        PRINT_PRIME;
    }
END
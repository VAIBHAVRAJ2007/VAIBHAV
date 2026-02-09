#include <stdio.h>
#define VAL_1(num) (num % 2 == 0)
#define PRINT_1 printf("%d is even", num);
#define PRINT_2 printf("%d is odd", num);
#define PRINT_NUMBER printf("Enter a number:");
#define SCAN_NUMBER scanf("%d", &num);
#define START int main(){
#define END return 0; }
START
    int num,a;
    PRINT_NUMBER;
    SCAN_NUMBER;
    if(VAL_1(num)){
        PRINT_1;
    }
    else
    PRINT_2;
END
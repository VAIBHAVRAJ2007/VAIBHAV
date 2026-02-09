// #include <stdio.h>
// #define LEAP(y) ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
// #define PRINT printf("Enter a year:");
// #define PRINT_1 printf("leap year");
// #define PRINT_2 printf("Not a leap year");
// #define SCAN scanf("%d",&yr) ;
// #define START int main(){
// #define END return 0;  }
// START
//     int yr;
//     PRINT;
//     SCAN;
//     if (LEAP(yr))
//     { 
//         PRINT_1;
//     }
//     else
//         PRINT_2;
// END
#include <stdio.h>

int main() {
    int y;
    printf("Year? ");
    scanf("%d", &y);

    if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
        printf("Leap year\n");
    else
        printf("Not a leap year\n");

    return 0;
}

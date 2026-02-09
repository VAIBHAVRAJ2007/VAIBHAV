#include <stdio.h>
enum DAY{MONDAY=1,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY};
int main()
{
    DAY DD = MONDAY;
    if(DD == 1)
        printf("MONDAY");
    else if (DD == 2)
        printf("TUESDAY");
    else if (DD == 3)
        printf("WEDNESDAY");
    else if (DD == 4)
        printf("THURSDAY");
    else if (DD == 5)
        printf("FRIDAY");

    return 0;
}
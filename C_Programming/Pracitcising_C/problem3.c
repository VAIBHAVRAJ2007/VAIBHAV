#include <stdio.h>

int main()
{
    float C,F;
    printf("Enter temperature in celsius:");
    scanf("%g",&C);
    F=(C*9/5)+32;
    printf("Temperature in Fahrenheit=%g",F);
    return 0;
}
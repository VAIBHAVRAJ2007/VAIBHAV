#include <stdio.h>

int main()
{
    float principal,rate,time,SI;
    printf("Enter principal amount:");
    scanf("%g",&principal);
    printf("Enter rate of interest:");
    scanf("%g",&rate);
    printf("Enter number of years:");
    scanf("%g",&time);
    SI=(principal*rate*time)/100;
    printf("Simple Interest for given amount=%g",SI);
    
    return 0;
}

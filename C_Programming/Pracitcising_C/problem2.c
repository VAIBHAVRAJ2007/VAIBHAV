#include <stdio.h>

int main()
{
    float pi=3.14,area1,h,r,area2;
    printf("Enter radius:");
    scanf("%g",&r);
    printf("Enter height:");
    scanf("%g",&h);
    area2=pi*r*r;   //area of circle
    area1=pi*r*r*h;   //volume of cylinder
    printf("vol. of cylinder=%g\n",area1);
    printf("area of circle=%g\n",area2);

    return 0;
}
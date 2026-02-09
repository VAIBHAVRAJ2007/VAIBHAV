/*Calculate income tax paid by an employee to the government as per the slabs mentioned below:
Income Slab Tax
2.5 – 5.0L 5%
5.0L - 10.0L 20%
Above 10.0L 30%
Note that there is no tax below 2.5L. Take income amount as an input from the user*/
#include <stdio.h>

int main()
{
    float income,tax;
    printf("Enter the income amount:");
    scanf("%f ",&income);
    if(income<250000) 
    {
        tax=0;
        printf("There is no need to pay tax.\n");
    }
    else if(income>=250000 && income<500000)
    {
        tax=income*0.05;
        printf("The tax to be paid is %g \n",tax);
    }
    else if(income>=500000 && income<1000000)
    {
        tax=income*0.2;
        printf("The tax to be paid is %g \n",tax);
    }
    else
    {
        tax=income*0.3;
        printf("The tax to be paid is %g \n",tax);
    }
    return 0;
}
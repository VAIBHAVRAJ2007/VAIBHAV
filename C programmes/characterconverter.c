#include<stdio.h>
int main()
{
    char alpha;
    printf("input alphabet\n");
    scanf("%c",& alpha);
    if (alpha>='A'&& alpha<='Z')
    {
        printf("input character is in upper case\n");
        printf("it's lower case = %c",alpha+32);
    }
    else
    {
        printf("input character is in lower case\n");
        printf("it's upper case = %c",alpha-32);
    }
    return 0;
}

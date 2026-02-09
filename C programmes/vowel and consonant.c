#include<stdio.h>
int main()
{
    char alpha;
    printf("enter an alphabet:");
    scanf("%c",&alpha);
    switch(alpha)
    {
    case'A':
    case'E':
    case'I':
    case'O':
    case'U':
    case'a':
    case'e':
    case'i':
    case'o':
    case'u':printf("it is a vowel\n");break;
    default:printf("It is a consonant\n");


    }
    return 0;

}

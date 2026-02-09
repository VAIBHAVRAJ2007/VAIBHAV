/*Write a program to determine whether a character entered by the user is 
lowercase or not. */
#include <stdio.h>
int main()
{
    char ch;
    printf("Enter character:");
    scanf("%c",&ch);
    if(ch>='a'&& ch<='z')
    {
        printf("Character is in lowercase\n");
        printf("The ASCII value of %c is %d\n",ch,ch);
    }
    else
    {
    printf("Character is not in lowercase\n");
    printf("The ASCII value of %c is %d\n",ch,ch);
    }
    return 0;
}
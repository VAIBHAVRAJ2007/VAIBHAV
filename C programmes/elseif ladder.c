#include<stdio.h>
int main()
{
    int x,y,sm,sb,m,q,r;
    char op;
    printf("enter x and y\n");
    scanf(" %d%d",&x,&y);
    printf("choose any operator(+,-,*,/,%)\n");
    scanf(" %c",&op);
    if (op=='+')
    {
        sm=x+y;
        printf("sum of x and y=%d",sm);
    }
    else if (op == '-')
    {
        sb=x-y;
        printf("difference b/w x and y=%d",sb);
    }
    else if (op == '*')
    {
        m=x*y;
        printf("product of x and y=%d",m);
    }
    else if (op=='/')
    {
        q=x/y;
        printf("quotient of x and y=%d",q);
    }
    else if (op=='%')
    {
        r=x%y;
        printf("remainder of x and y=%d",r);
    }
    else
    {
    printf("not a valid operator");
    }
    return 0;
}

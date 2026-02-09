#include<stdio.h>
int main()
{
	//variables used//
	int a,b,c,d,e,f,sum1,sum2,sum3;

	//input from user//
	printf("enter a and b\n");
	scanf("%d\n%d",&a,&b);

	//  adding a and b (decimals)  //
    sum1=a+b;

    // convert a and b  into hexadecimals//
    printf("c=");
    printf("%x\n",a);
    printf("d=");
    printf("%x\n",b);

    //adding c and d (hexadecimals) //
    sum2=a+b;

    //convert a and b into octals//
    printf("e=");
    printf("%o\n",a);
    printf("f=");
    printf("%o\n",b);

    //adding e and f (octals)//
    sum3=a+b;

    // printing sum 1=sum of a and b (decimals) //
    printf("sum 1=%d\n",sum1);

    //printing sum 2=sum of c and d (hexadecimals) //
    printf("sum 2=%x\n",sum2);

    //printing sum 3=sum of e and f (octals)//
    printf("sum 3=%o\n",sum3);


    //address of byte of each variable in memory//
	printf("%x\n",&sum1);
	printf("%x\n",&sum2);
	printf("%x\n",&sum3);
	printf("%x\n",&a);
	printf("%x\n",&b);
	printf("%x\n",&c);
	printf("%x\n",&d);
	printf("%x\n",&e);
	printf("%x\n",&f);


    return 0;
}

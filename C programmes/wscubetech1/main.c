#include <stdio.h>
//#include <string.h>
/*#include<stdbool.h>*/
//int main()
//{
	/**int a,b;
	a=18;
	b=658;
	printf("%-3d",a);
	printf("%d",b);
	printf("hello\n");
	printf("hi\n");
	printf("yes");
	int marks=30;**/

	// IF ELSE//
	/**
	_Bool a;
	if(a=0)
	{
	printf("pass");
	}
	else
	{
		printf("fail");
	}
	bool a=true;
	if(a)
		printf(" Hi");
	else
		printf("Bye");*/

	// switch case //

	/**
	/**int a;
	scanf("%d",&a);
	switch(a)
	{
		case 1: printf("A");break;
		case 2: printf("B");break;
		case 3: printf("C");break;
		case 4: printf("D");break;
		case 5: printf("E");break;
	   default: printf("Apple");
	}
		printf("\n");
		printf(" Raj");**/

	// ITERATION   //

	//    for loop     //

	/**int i=0,sum=0;
	for(i=1;i<=10;i++)
	{
		sum=sum+i;
	}
	printf("%d\n",sum);
	printf("%d\n",i);     */

	//	while loop   //

	// count number of digits in a number  //

	/**int a=0,c=0;
	scanf("%d",&a);
	while(a>0)
	{
			a=a/10;
			c++;
	}
	   printf("%d",c);*/

	//    while loop    //
	// sum of digits in a number //

	/*int num,sum=0;
		scanf("%d",&num);
		while(num>0)
	 {
		 sum=sum+num%10;
		num=num/10;
	  }
		printf("sum=%d\n",sum);*/

	/* do while loop //


//CALCULATOR//

/**int choice,a,b;
do
{
printf("\n                                                Calculator\n");
printf("Choices Available:");
printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.EXIT\n");
printf("Enter your desired choice:");
scanf("%d",&choice);

if(choice==1)
{
printf("Enter a:");
scanf("%d",&a);
printf("Enter b:");
scanf("%d",&b);
printf("result=%d",a+b);
}

if(choice==2)
{
printf("Enter a:");
scanf("%d",&a);
printf("Enter b:");
scanf("%d",&b);
printf("result=%d",a-b);
}

if(choice==3)
{
printf("Enter a:");
scanf("%d",&a);
printf("Enter b:");
scanf("%d",&b);
printf("result=%d",a*b);
}

if(choice==4)
{
printf("Enter a:");
scanf("%d",&a);
printf("Enter b:");
scanf("%d",&b);
printf("result=%d",a/b);
}

if(choice==5)
{
break;
}


}while(1);*/

	/*   int i=1;
	do
	{
	printf("%d\t",i);
	i++;


   }while(i<=5);   */

	// BREAK//

	/**int i;
	for(i=1;i<=10;i++)
	{
		if(i==8)
			break;
		else
			printf("%d\n",i);
	}*/

	//  to check prime or not using (for loop),if,break,if-else  //

	/**int i=0,n=0,r;
	scanf("%d",&n);
	for(i=n-1;i>=2;i--)
	{
		r=n%i;
				if(r==0)
					break;
	}
	printf(" divisor = %d ",i);
	printf(" remainder = %d ",r);
	if(r==1)
		printf(" prime ");
	else
		printf(" NOT prime ");*/

	//  CONTINUE //

	// FOR LOOP  //
	/**int i;
	for(i=1;i<=5;i++)
	{
		if(i==3)
			continue;
		else
			printf("%d\t",i);
	}*/

	//  WHILE LOOP   //

	/** int i=1;
	 while(i<=5)
	 {
		i++;
		if(i==3)
			continue;
		else
			printf("%d\t",i);
	 }*/

	// DO WHILE //

	/**int i=1;
	do
	{
	   i++;
	   if(i==3)
		   continue;
	   else
		   printf("%d\t",i);

	}while(i<=5);*/

	/**        VARIABLE   POINTER                //


//    DECLARATION   //   INITIALISATION   //    SIZE  //




/*int a=5,*p=&a;
float b=6.9,*q=&b;

printf("%x\t",p);
printf("%d\t",*p);
printf("%d\t",sizeof(p));

printf("%x\t",q);
printf("%g\t",*q);
printf("%d\t",sizeof(q));*/

	/**int a=300,*p=&a;
	char *q;
	printf("%d\n",*p);
	printf("%x\n",p);
	q=&a;
	printf("%x\n",q);
	printf("%c",*q);*/

	//     ALIASING    //

	/**int a=5,*p=&a;
	printf("%d\n",*(p+0));
	printf("%d\n",p[0]);*/

	/*  TYPE OF VARIaBLE POINTER  //


  //           1. WILD POINTER              //

  //		       2.NULL POINTER             //






//              3.VOID POINTER           //


/**int a=5;
float b=5.6f;
double c=50.567;
void *p;
p=&a;
printf("%d\n",*(int *)p);
p=&b;
printf("%g\n",*(float *)p);
p=&c;
printf("%lg",*(double *)p);*/

	//                 POINTER TO CONSTANT VARIABLE                 //

	/* int a=5;
	 const int b=6;                     //constant variable//
	 int *p;
	 int const *q; */
	/* p=&a;
		 printf("%d\n%d\n",*p,a);
		 p=&b;                                     //not to do//
		 printf("%d\n",*p);
		 *p=11;
		 printf("%d\n",*p);
		 printf("%d\n",b);  */
	/*  q=&a;                                      //not to do//
		  printf("%d\n%d\n",*q,a);
		  a=21;
		  printf("%d\n%d\n",*q,a);
		  q=&b;
		  printf("%d\n%d\n",*q,b); */

	/* const int b=5;
	 int *p;
	 p=&b;                                       //not to do//
	 *p= 10;
	 printf("%d\n",b);
	 printf("%d",*p);  */

	/*		 int a=5;
			 const int b=6;
			 int *p;
			 const int *q;
			 q=&a;                                        //not to do//
			 a=15;
			 printf("%d\n",a);
			 printf("%d\n",*q);
			 p=&b;                                      //not to do//
			 *p=12;
			 printf("%d\n",b);
			 printf("%d\n",*p);      */

	// CORRECT//

	/*     int a=5;
			 const int b=6;
			 int *p;
			 const int *q;
			 p=&a;
			 q=&b;
			 printf("%d\n",a);
			 printf("%d\n",*p);
			 a=19;
			 printf("%d\n",a);
			 printf("%d\n",*p);
			 printf("%d\n",b);
			 printf("%d\n",*q);    */

	/*  CONST POINTER  //

   // {DATA TYPE(int)} *{CONST P(const p)} //




/*    int a=5;
int b=6;
int *const p=&a;                                  // constant pointer //
//p=&b;//                                               \\       not valid       //
printf("%d\n",*p);
printf("%x\n",p);
*p=20;
printf("%d\n",a);
printf("%d\n",*p);   */

	/**int a=5;
	const  int b=6,c=7;               // constant integer //
	void *r;
	int *const p=&a;                 // constant pointer //
	const int *q=&b;                 // pointer to constant variable //
	 //q=&c;//                            \\                  valid                       //
   // *q=9;                                 //              not valid                   //
	printf("a=%d\n",a);
	printf("*p=%d\n",*p);
	printf("b=%d\n",b);
	printf("*q=%d\n",*q);
	q=&c;
	printf("*q=%d\n",*q);
	printf("c=%d\n",c);
	r=&a;
	printf("a*r=%d\n",*(int *)r);
	*(int*)r=4;
	 printf("a*r=%d\n",*(int *)r);
	 printf("a=%d\n",a);
	r=&b;
	printf("b*r=%d\n",*(int *)r);
	*(int*)r=90;
	printf("b*r=%d\n",*(int *)r);
	printf("b=%d\n",b);
	r=&c;
	printf("c*r=%d\n",*(int *)r);
	*(int*)r=60;
	printf("c*r=%d\n",*(int *)r);
	printf("c=%d\n",c);*/

	// FUNCTION POINTER //
void hello()
{
	int i,n;
	scanf("%d",&n);
		char b[n];
		//b[0]='h';
		//b[1]='e';
		//b[2]='l';
		//b[3]='l';
		//b[4]='o';
		//b[5]='\0';
		for (i = 0; i <= n; i++)
			scanf("%c", &b[i]);
		for (i = 0; i <= n; i++)
			printf("%c", b[i]);
			//printf("\n");
		//printf("%lu", sizeof(b));
		//printf("\n");
}
void hi()
{
/*	char *a="WORLD";
	//printf("\n");
	printf("%s\n", a);
	
	printf("%c\n",a[3]);
	printf("%s\n", a);
  	printf("%lu", sizeof(a));*/
}
int main()
{
void (*p) ();
p=hello;
p();
p=hi;
p();
return 0;
}

	/**POINTER TO POINTER*/

	/*int a=5;
	int *p;
	int **q;
	int ***r;

	q=&p;
	p=&a;
	r=&q;

	printf("%x\n",*q);
	printf("%x\n",p);
	printf("%d\n",**q);
	printf("%d\n",*p);
	printf("%x\n",q);
	printf("%x\n",q);
	printf("%x\n",q);
	printf("%x\n",q);
	printf("%x\n",q);*/

	/**  ARRAY */

	// int arr[]={0,1,2,3,4};
	// for(int i=0;i<5;i++)
	// {
	// 	printf("%d\n",arr[i]);
	// }
	// printf("%d\n",sizeof(arr[2]));

	// Designated Initialization

	// int arr[6];
	//  for(int i=0;i<6;i++)
	//  	{
	//  		scanf("%d\n",&arr[i]);
	//  	}
	//  	printf("\n");
	//  	for(int i=0;i<6;i++)
	//  	{
	//  		printf("%d\t",arr[i]);
	//  	}

	// Size of Array

	// int arr[10];
	// printf("%lu\t", sizeof(arr));
	// printf("%lu\n", sizeof(arr[0]));
	// printf("no of elements=%lu", sizeof(arr)/sizeof(arr[0]));

	// Constant Array

	// const int arr[] = {1, 2, 3, 4, 5};
	// //arr[3] = 33;  value cannot change
	// for(int i = 0; i < 5; i++) {
	// 	printf("%d\n", arr[i]);
	// }

	// Variable length Array

	// int n;
	// printf("Enter no. of elements in array:");
	// scanf("%d",&n);
	// int arr[n];
	// printf("%lu\n",sizeof(arr));
	// printf("Enter elements in array:\n");
	// for(int i=0;i<n;i++)
	// {
	// 		scanf("%d",&arr[i]);
	// }

	// for(int i=0;i<n;i++)
	// {
	// 		printf("%d\t",arr[i]);
	// }

	// Array and Pointer Arithmetic

	// int a[5] = {1, 2, 3, 4, 5};
	// int *p,*q;
	// p=&a[5];
	// q=&a[0];

	// //printf("%d",*(p+2));
	// printf("%d",q-p);

	// Pointer Progressive

	/*int arr[9]={44,665,889,55,554,558,4478,5845,525};
	int *p=arr;

	for (int i = 8 ; i>=0 ; i--)
	{
		printf("%d\t",*p);
	}*/
	// printf("%s","58");
	// );
	// printf("%c", "VAI"[5]);
	// char a[50] = {'a', 'b', 'c', 'd'};
	// char *a="hello";
	// printf("%s",a);
	// printf("%lu", sizeof(a));
	// printf("%s", a);
	/*int i;
	char b[20];
	for (i = 0; i <= 10; i++)
		scanf("%c", &b[i]);
	for (i = 0; i <= 10; i++)
		printf("%c", b[i]);

	char a[10] = "hello";
	a[2] = 'a';
	printf("%s", a);*/
	/*return 0;
}*/

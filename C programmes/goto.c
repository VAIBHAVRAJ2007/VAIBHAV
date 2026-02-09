#include<stdio.h>
    main()
  {
       int num,r;
    printf("enter a number\n");
                 scanf("%d",&num);
    r=num%2;
               if (r==0)
    {
        goto L1;

    }
               else
    {
        goto L2;
    }
                          L1: printf( " even number\n");


                                              L2: printf( " odd number\n");
    return 0;
                                                                                }

#include <stdio.h>
int main()
{
    int a = 1, *iptr = &a;
    // float b = 7.5, *fptr = &b;
    // char ch = 'a', *cptr = &ch;
    printf("address of a=%u\n", iptr);
    printf("address of a=%u\n", &a);
// /*1*/         int x = *(iptr++);
//               printf("%d\n", x);
//               printf("%d\n", a);
//               printf("%u\n", iptr);
//               printf("%d\n", *iptr);

// /*2*/          int x = *++iptr;
//                printf("%d\n", x);
//                printf("%d\n", a);
//                printf("%u\n", iptr);
//                printf("%d\n", *iptr);

// /*3*/          int x = ++*iptr;
//                printf("%d\n", x);
//                printf("%d\n", a);
//                printf("%u\n", iptr);
//                printf("%d\n", *iptr);

// /*4*/          int x = (*iptr)++;
//                printf("%d\n", x);
//                printf("%d\n", a);
//                printf("%u\n", iptr);
//                printf("%d\n", *iptr);

    return 0;
}
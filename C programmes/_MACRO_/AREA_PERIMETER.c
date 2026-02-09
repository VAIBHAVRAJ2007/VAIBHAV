#include <stdio.h>
#define AREA(length,breadth) (length*breadth)
#define PERIMETER(length,breadth) (2*(length+breadth))
#define START int main(){
#define END return 0; }
START
    int len, bred,area,peri;
    printf("Enter dimensions:");
    scanf("%d %d", &len, &bred);
    area = AREA(len, bred);
    peri = PERIMETER(len, bred);
    printf("Length = %d\n", len);
    printf("Breadth = %d\n", bred);
    printf("Area = %d\n", area);
    printf("Perimeter = %d", peri);
END
#include <stdio.h>
int main() 

{    
for (int i = 1; i <= 3; i++) 
    {
        for (int j = 1; j <= 3; j++) 
            {
                if (i == j)
                {
                    continue;
                }
                if (i + j == 4) 
                {
                    break;
                }
                printf("%d%d ", i, j);
            }
        printf("\n");
    }
return 0;
}
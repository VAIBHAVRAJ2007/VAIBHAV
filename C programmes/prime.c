#include <stdio.h>

int main()
{
  int num, i, flag = 0;
  printf("Enter a number to check whether prime or composite: ");
  scanf("%d", &num);
  if (num == 0 || num == 1)
  flag = 1;

  for (i = 2; i <= num / 2; ++i)
  {
    if (num % i == 0)

    {
      flag = 1;
      break;
    }
  }

  if (flag == 0)
    printf("Entered number %d is a prime number.", num);
  else
    printf("Entered number %d is a composite number.", num);

  return 0;
}

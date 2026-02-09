#include <stdio.h>

int main() {

  //Here flag value 0 means prime number and
  //1 means non-prime number
  int num, i, flag = 0;
  printf("Enter a number to check whether prime or not: ");
  scanf("%d", &num);

  // 0 and 1 are not the prime numbers so setting
  // the flag to 1 if entered number is 0 or 1
  if (num == 0 || num == 1)
  flag = 1;

  for (i = 2; i <= num / 2; ++i) {

    // if num is divisible by i, then num is not prime
    // change the flag value to 1
    if (num % i == 0) {
      flag = 1;
      break;
    }
  }

  // If flag is 0 it means the number is prime
  if (flag == 0)
    printf("Entered number %d is a prime number.", num);
  else
    printf("Entered number %d is not a prime number.", num);

  return 0;
}

 #include<stdio.h>
 #include<math.h>
 int main()
{
	int num,originalNum,remainder, result = 0, n = 0;
	//Get input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    originalNum = num;
	//Count the number of digits
		while (originalNum != 0)
	{
        originalNum=originalNum / 10;
        n++;
	}
		printf("number of digits = %d \n",n);

		originalNum = num;

		//Calculate the sum of the powers of digits
		while (originalNum != 0)
	{
        remainder = originalNum % 10;
        result += ((int)pow(remainder,n)); //Raising digit to the power of n
        originalNum=originalNum /10;
	}
		printf("sum of powers of digits = %d\n",n);

					if (result == num)
        printf("%d is an Armstrong number.\n", num);
					else
        printf("%d is not an Armstrong number.\n", num);

		return 0;
}

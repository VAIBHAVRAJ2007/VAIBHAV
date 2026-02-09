#include<stdio.h>
int main()
{
	float celsius, fahrenheit;
	printf("enter temperature in fahrenheit");
	scanf("%f", &fahrenheit);
	celsius=(fahrenheit-32)*5/9;
	printf("temperature in celsius = %fahrenheit",celsius);
	return 0;
}

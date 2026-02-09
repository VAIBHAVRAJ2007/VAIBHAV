#include<iostream>
int main()
{
    int num1, den1, num2, den2;
    std::cout << "Enter num1:";
    std::cin >> num1;
    std::cout << "Enter den1:";
    std::cin >> den1;
    std::cout << "Enter num2:";
    std::cin >> num2;
    std::cout << "Enter den2:";
    std::cin >> den2;
    float s = (((num1*den2) + (num2*den1))/(den1*den2));
    std::cout << "Sum is " << s;
    return 0;
}
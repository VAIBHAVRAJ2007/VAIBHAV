#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Enter side a:";
    cin >> a;
    cout << "Enter side b:";
    cin >> b;
    cout << "Enter side c:";
    cin >> c;
    if (a == b && a == c)
        cout << "Equilateral triangle";
    else if (a != b && b != c && a != c)
        cout << "Scalene triangle";
    else  
        cout << "Isosceles triangle";
    
    return 0;
}
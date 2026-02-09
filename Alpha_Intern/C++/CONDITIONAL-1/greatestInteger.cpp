#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter a number " ;
    cin >> a;
    cout << "Enter another number" ;
    cin >> b;
    if(a>b)
        cout << a << " is greatest.";
    else
        cout << b << " is greatest";
    return 0;
}
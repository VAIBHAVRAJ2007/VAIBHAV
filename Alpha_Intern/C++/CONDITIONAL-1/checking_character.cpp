#include<iostream>
using namespace std;
int main()
{
    char x;
    cout << "Enter a character: ";
    cin >> x;
    if ((int)x >= 48 && (int)x <= 57)
        cout << x << " is a digit. " << "ASCII of " << x << ':' << (int)x;
    else if ((int)x >= 65 && (int)x <= 90||(int)x >= 97 && (int)x <= 122)
        cout << x << " is a alphabet. " << "ASCII of " << x << ':' << (int)x;
    else
        cout << x << " is a special character. " << "ASCII of " << x << ':' << (int)x;
        return 0;
}
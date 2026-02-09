#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    while (n >= 1)
    {
        cout << n << " ";
        n--;
    }
    
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cout << "Enter an integer:";
    cin >> n;
    int m = n;
    while (1<=n){
        sum = sum + n;
        n--;
    }
    cout << "Sum of first " << m << " natural numbers is ";
    cout << sum;
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int a, n, d, Tn;
    cout << "Enter number of terms:";
    cin >> n;
    cout << "Enter first term:";
    cin >> a;
    cout << "Enter common difference:";
    cin >> d;
    Tn = a + (n - 1) * d;
    for (int i = a; i <= Tn;i+=d)
        cout << i << "_";
    return 0;
}
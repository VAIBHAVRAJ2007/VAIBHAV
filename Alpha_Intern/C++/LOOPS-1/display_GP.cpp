#include <iostream>
using namespace std;
int main()
{
    int a, n, r;
    cout << "Enter number of terms:";
    cin >> n;
    cout << "Enter first term:";
    cin >> a;
    cout << "Enter common ratio:";
    cin >> r;
    for (int i = 0; i < n; i++){
        cout << a << " ";
        a *= r;
    }
    return 0;
}
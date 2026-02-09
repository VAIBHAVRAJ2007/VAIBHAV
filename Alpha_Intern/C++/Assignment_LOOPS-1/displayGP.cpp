#include <iostream>
#include<math.h>
using namespace std;
int main()
{
    int i,n,a,Tn,r;
    cout << "Enter number of terms:";
    cin >> n;
    cout << "Enter first term:";
    cin >> a;
    cout << "Common Ratio:";
    cin >> r;
    // for (i = 0; i <= n; i++ ){
    //     cout << a << " ";
    //     a *= r;
    // }
    // Tn = a * pow(r, n - 1);
    // for (i = a; i <= Tn; i*=r ){
    //     cout << i << " ";
    // }
    return 0;
}
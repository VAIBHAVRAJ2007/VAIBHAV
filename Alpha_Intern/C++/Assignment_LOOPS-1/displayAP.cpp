#include <iostream>
using namespace std;
int main()
{
    float i,n,a,d,Tn;
    cout << "Enter number of terms:";
    cin >> n;
    cout << "Enter first term:";
    cin >> a;
    cout << "Common Difference:";
    cin >> d;
    Tn=a+(n-1)*d;
    for (i = a; i <= Tn; i+=d )
        cout << i << " "; 
        return 0;
}
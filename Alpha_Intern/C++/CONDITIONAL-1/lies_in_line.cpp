#include<iostream>
using namespace std;
int main()
{
    int x1, x2, x3, y1, y2, y3,m1,m2,m3;
    cout << "Enter first co-ordinate:";
    cin >> x1 >> y1;
    cout << "Enter second co-ordinate:";
    cin >> x2 >> y2;
    cout << "Enter third co-ordinate:";
    cin >> x3 >> y3;
    m1=(y2-y1)/(x2-x1);
    m2=(y3-y2)/(x3-x2);
    if(m1==m2)
        cout << "All three points lie on one straight line";
    else
    cout<<"All three points do not lie on one straight line";

    return 0;
} 
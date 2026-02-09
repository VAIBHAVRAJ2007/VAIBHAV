#include<iostream>
using namespace std;
int main()
{
    int h, l, c, d;
    cout << "Enter no. of heads:";
    cin >> h;
    cout << "Enter no. of legs:";
    cin >> l;
    c = (4*h - l) / 2;
    d = h - c;
    cout << "No. of dog:" << d << endl;
    cout << "No. of chicken:" << c;
    return 0;
}
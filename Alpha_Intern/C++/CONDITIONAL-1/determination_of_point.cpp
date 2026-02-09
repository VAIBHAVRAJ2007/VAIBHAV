#include<iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "Enter x coordinate:";
    cin >> x;
    cout << "Enter y coordinate:";
    cin >> y;
    if (x!=0 && y == 0)
        cout << '(' << x << "," << y << ')' << " lies on x-axis.";
    else if (x == 0 && y!=0)
        cout << '(' << x << "," << y << ')' << " lies on y-axis.";
    else if(x==0&&y==0)
        cout << '(' << x << "," << y << ')' << " is origin.";
    else
        cout << '(' << x << "," << y << ')' << " lies in plain. ";
    return 0;
} 
#include<iostream>
using namespace std;
int main()
{
    int hr, min;
    cout<<"Enter hour:";
    cin >> hr;
    cout << "Enter minute:";
    cin >> min;
    int angle1 = hr * 30;
    int angle2 = min * 6;
    short int minAngle = angle1 - angle2;
    cout << minAngle;
    return 0;
}
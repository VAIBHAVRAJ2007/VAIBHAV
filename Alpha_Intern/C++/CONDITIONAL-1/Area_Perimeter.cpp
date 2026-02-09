#include<iostream>
using namespace std;
int main()
{
    float len, bred;
    cout << "Enter length:";
    cin >> len;
    cout << "Enter breadth:";
    cin >> bred;
    float area = len * bred;
    float peri = 2 * (len + bred);
    if(area>peri)
        cout << "area is greater than perimeter." << endl
             << area;
    else if(area<peri)
        cout << "perimeter is greater than area." << endl
             << peri;
    else
        cout << "area is equal to perimeter." << endl
             << area << endl
             << peri;
    return 0;
}
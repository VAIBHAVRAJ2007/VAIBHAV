#include<iostream>
using namespace std;
int main()
{
    float r;
    cout << "Enter radius:";
    cin >> r;
    float pi = 3.1415;
    float area = pi * r * r;
    float circ = 2 * pi * r;
    if(area>circ)
        cout << "Area is large." << endl
             << area;

    else if (area<circ)
        cout << "Circumference is large." << endl
             << circ;
    else
        cout << "area is equal to circumference" << endl
             << area << endl
             << circ;
    return 0;
}
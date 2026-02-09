#include<iostream>
using namespace std;
int main()
{
    int A,B,C;
    cout << "Enter marks of A:";
    cin >> A;
    cout << "Enter marks of B:";
    cin >> B;
    cout << "Enter marks of C:";
    cin >> C;
    if (A < B && A < C)
        cout << "A has least marks";
    else if (B < A && B < C)
        cout << "B has least marks";
    else
        cout << "C has least marks";
    return 0;
}
#include <iostream>
using namespace std;
int input(int[]);
void print(int[], int);
void selection_Sort(int[], int);
void print(int a[], int n)
{
    int i;
    cout << "After sorting:";
    for (i = 0; i < n; i++)
        cout << a[i] << "   ";
}
void selection_Sort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
int main()
{
    int a[100], num;
    num = input(a);
    selection_Sort(a, num);
    print(a, num);
    return 0;
}
int input(int a[])
{
    int i, n;
    cout << "Enter number of elements:";
    cin >> n;
    cout << "Enter " << n << " elements" << '\n';
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> a[i];
    }
    return n;
}
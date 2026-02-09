#include <iostream>
using namespace std;
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int a[100], i, n, *arr;
    cout << "Enter range: ";
    cin >> n;
    cout << "Enter " << n << " numbers:\n";
    for (i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> a[i];
    }
    bubbleSort(a, n);
    cout << "After sorting:";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
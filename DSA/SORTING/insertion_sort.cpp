#include <iostream>
using namespace std;
int main()
{
    int a[100];
    int i, j, key, n;
    cout << "Enter range:";
    cin >> n;
    cout << "Enter " << n << " number in array\n";
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> a[i];
    }
    for (j = 1; j < n; j++)
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }

    // for (i = 1; i < n; i++)
    // {
    //     for (j = i; j > 0; j--)
    //     {
    //         if (a[j] < a[j - 1])
    //             swap(a[j], a[j - 1]);
    //         else
    //             break;
    //     }
    // }
    // for (i = n - 2; i >= 0; i--)
    // {
    //     for (j = i; j < n; j++)
    //     {
    //         if (a[j] < a[j + 1])
    //             swap(a[j], a[j + 1]);
    //         else
    //             break;
    //     }
    // }
    cout << "Sorted Array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
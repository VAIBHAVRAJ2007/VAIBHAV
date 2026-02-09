#include <iostream>
// #include <stdlib.h>
using namespace std;
void binarySearch(int n, int *arr, int search)
{
    int m, l = 0, r = n - 1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (arr[m] == search)
        {
            cout << "Element is found at " << m + 1;
            break;
        }
        else if (arr[m] < search)
        {
            l = m + 1;
        }
        else if (arr[m] > search)
        {
            r = m - 1;
        }
        if (l > r)
        {
            cout << "Element is not found.";
        }
    }
}
int main()
{
    int n, *arr, search, l = 0, r, m;
    cout << "Enter no. of elements ";
    cin >> n;
    arr = (int *)calloc(n, sizeof(int));
    cout << "Enter " << n << " elements in ascending order:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter element you want to search:";
    cin >> search;
    binarySearch(n, arr, search);
    free(arr);
    return 0;
}
#include <iostream>
using namespace std;
int partition(int a[], int start, int end)
{
    int pos = start, i;
    for (i = start; i <= end; i++)
    {
        if (a[end] >= a[i])
        {
            swap(a[i], a[pos]);
            pos++;
        }
    }
    return (pos - 1);
}
void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
    int pivot = partition(a, start, end);
    quickSort(a, start, pivot - 1); // left
    quickSort(a, pivot + 1, end);   // right
    }
}
int main()
{
    int a[100], n, i;
    cout << "Enter range: ";
    cin >> n;
    cout << "Enter " << n << " numbers in array\n";
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " ";
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    cout << "After sorting: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
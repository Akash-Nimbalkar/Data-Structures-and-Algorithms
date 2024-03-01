#include <iostream>
using namespace std;
int Partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }
    int pivotIndex = s + cnt;

    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j++]);
        }
    }
    return pivotIndex;
}
void QuickSort(int *arr, int s, int e)
{
    if (s >= e) // B.C.
        return;

    int p = Partition(arr, s, e); // Partitioning array

    QuickSort(arr, s, p - 1);

    QuickSort(arr, p + 1, e);
}
int main()
{
    int arr[6] = {16, 2, 4, 99, 4, 1};
    int n = 6;
    QuickSort(arr, 0, n - 1);
    cout << "Sorted :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
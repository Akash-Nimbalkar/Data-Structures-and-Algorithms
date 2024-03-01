#include <iostream>
using namespace std;
void bubblesort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubblesort(arr, n - 1);
}
int main()
{
    int arr[] = {2, 6, 8, 3, 1};
    bubblesort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
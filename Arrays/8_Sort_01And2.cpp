#include <iostream>
using namespace std;
void sort012(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == 0)
            i++;
        if (arr[j] == 2)
            j--;
        if ((arr[i] = 2 && arr[j] == 0) || (arr[i] = 2 && arr[j] == 1) && i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[20], n;
    cout << "Enter size of array" << endl;
    cin >> n;
    cout << "Enter " << n << " array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort012(arr, n);

    cout << "Array after function call : " << endl;
    printArray(arr, n);

    return 0;
}
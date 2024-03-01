#include <iostream>
using namespace std;
bool binary_search(int arr[], int s, int e, int k)
{
    if (s > e)
        return false;
    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
        return true;
    if (arr[mid] > k)
    {
        return binary_search(arr, s, mid - 1, k);
    }
    else
    {
        return binary_search(arr, mid + 1, e, k);
    }
}
int main()
{
    int arr[20], n, key;
    cout << "Enter size of array " << endl;
    cin >> n;
    cout << "Enter " << n << " array elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Key to search is :" << endl;
    cin >> key;
    cout << binary_search(arr, 0, n - 1, key);

    return 0;
}
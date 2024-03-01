#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n, int key)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        else if (arr[mid] > key)
        {
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[20], n, key;
    cout << "Enter size of array" << endl;
    cin >> n;
    cout << "Enter " << n << " array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key to search" << endl;
    cin >> key;
    int ans = BinarySearch(arr, n, key);

    cout << "Key " << key << " is present in array at index " << ans << endl;

    return 0;
}
#include <iostream>
using namespace std;
bool LinearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return 1;
    }
    return 0;
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
    bool found = LinearSearch(arr, n, key);
    if (found)
    {
        cout << "Key " << key << " is present in array" << endl;
    }
    else
    {
        cout << "Key " << key << " is not present in array" << endl;
    }

    return 0;
}
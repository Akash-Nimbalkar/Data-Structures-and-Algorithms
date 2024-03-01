#include <iostream>
using namespace std;
int First_Occ(int arr[], int n, int key)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2, temp = -1;
    ;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            temp = mid;
            e = mid - 1;
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
    return temp;
}

int Last_Occ(int arr[], int n, int key)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2, var = -1;
    ;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            var = mid;
            s = mid + 1;
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
    return var;
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
    int ans1 = First_Occ(arr, n, key);
    int ans2 = Last_Occ(arr, n, key);
    int total = (ans2 - ans1) + 1;

    cout << "Key " << key << " has first occurence at index " << ans1 << endl;
    cout << "Key " << key << " has last occurence at index " << ans2 << endl;
    cout << "Key " << key << " occurs in array " << total << " times" << endl;

    return 0;
}
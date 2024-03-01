// Find duplicate element in an array
#include <iostream>
using namespace std;

int find_duplicate(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{

    int arr[20], n;
    cout << "Enter size of array elements" << endl;
    cin >> n;
    cout << "Enter " << n << " array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int c = find_duplicate(arr, n);
    cout << "The duplicate element present in array is " << c << endl;

    return 0;
}

// approach 2
#include <iostream>
using namespace std;

int find_duplicate(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum - (n * (n - 1)) / 2;
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

    int c = find_duplicate(arr, n);
    cout << "The duplicate element present in array is " << c << endl;

    return 0;
}
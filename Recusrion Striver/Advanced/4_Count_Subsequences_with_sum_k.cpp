#include <bits/stdc++.h>
using namespace std;

int print(int ind, int sum, int k, int arr[], int n)
{

    if (sum > k) // Not satisifed condition. Can be done only when array elements are positive.
    {
        return 0;
    }
    if (ind == n)
    { // Condition Satisfied
        if (sum == k)
        {
            return 1;
        }
        // Condition not satisfied
        else
            return 0;
    }

    // Take Case (Take element into the subsequence)

    sum += arr[ind];
    int l = print(ind + 1, sum, k, arr, n);

    sum -= arr[ind];
    // Not Take Case (Element is not taken into the subsequence)
    int r = print(ind + 1, sum, k, arr, n);

    return l + r;
}

int main()
{
    int n, arr[20];
    cout << "Enter no. of array elements" << endl;
    cin >> n;

    cout << "Enter " << n << " array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "There are " << print(0, 0, 10, arr, n) << " Subsequences with sum equal to " << 10 << endl;

    return 0;
}
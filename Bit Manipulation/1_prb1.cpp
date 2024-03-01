// Given an array of size n where every number occurs twice except one number. You need to print that unique number.

#include <bits/stdc++.h>
using namespace std;

int printUnique(int arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}
int main()
{
    int n;
    cout << "Enter no. of array elements" << endl;
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The unique integer in given array is " << printUnique(arr, n) << endl;

    return 0;
}
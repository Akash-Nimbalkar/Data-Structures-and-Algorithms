// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int K, int arr[], int n)
{
    int sum = 0, i = 0, j = 0, maxi = INT_MIN;

    while (j < n)
    {
        sum = sum + arr[j];

        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            maxi = max(maxi, sum);
            sum = sum - arr[i];
            j++;
            i++;
        }
    }

    return maxi;
}
int main()
{
    int n, arr[25], K = 3;

    cout << "Enter size of array : ";
    cin >> n;

    cout << "Enter " << n << " array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The maximum sum of a subarray of size K is " << maximumSumSubarray(K, arr, n);
    return 0;
}
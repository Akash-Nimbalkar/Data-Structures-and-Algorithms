#include <bits/stdc++.h>
using namespace std;

bool print(int ind, vector<int> &ans, int sum, int k, int arr[], int n)
{
    if (ind == n)
    { // Condition Satisfied
        if (sum == k)
        {
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
            return true;
        }
        // Condition not satisfied
        else
            return false;
    }

    // Take Case (Take element into the subsequence)

    sum += arr[ind];
    ans.push_back(arr[ind]);
    if (print(ind + 1, ans, sum, k, arr, n) == true)
    {
        return true;
    }

    sum -= arr[ind];
    ans.pop_back();
    // Not Take Case (Element is not taken into the subsequence)
    if (print(ind + 1, ans, sum, k, arr, n) == true)
    {
        return true;
    }

    return false;
}

int main()
{
    int n, arr[20];
    vector<int> ans;
    cout << "Enter no. of array elements" << endl;
    cin >> n;

    cout << "Enter " << n << " array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    print(0, ans, 0, 2, arr, n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void print(int ind, vector<int> &ans, int sum, int k, int arr[], int n)
{
    if (ind == n)
    {
        if (sum == k)
        {

            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // Take Case (Take element into the subsequence)

    sum += arr[ind];
    ans.push_back(arr[ind]);
    print(ind + 1, ans, sum, k, arr, n);

    sum -= arr[ind];
    ans.pop_back();
    // Not Take Case (Element is not taken into the subsequence)
    print(ind + 1, ans, sum, k, arr, n);
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
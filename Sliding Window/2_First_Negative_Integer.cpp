// Given an array A[] of size N and a positive integer K
// find the first negative integer for each and every window(contiguous subarray) of size K.

#include <bits/stdc++.h>
using namespace std;

vector<int> brute_force(int arr[], int n, int K)
{

    vector<int> ans;

    for (int i = 0; i <= n - K; i++)
    {
        bool found = false;
        for (int j = i; j < i + K; j++)
        {
            if (arr[j] < 0)
            {
                ans.push_back(arr[j]);
                found = true;
                break;
            }
        }
        if (!found)
            ans.push_back(0);
    }

    return ans;
}

vector<int> FirstNegativeInteger(int arr[], int n, int K)
{

    list<int> v;
    vector<int> ans;

    int i = 0, j = 0;

    while (j < n)
    {
        if (arr[j] < 0)
        {
            v.push_back(arr[j]);
        }

        if (j - i + 1 < K)
        {
            j++;
        }

        else if (j - i + 1 == K)
        {
            if (v.size() == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(v.front());
                
                if (arr[i] == v.front())
                {

                    v.pop_front();
                }
            }
            i++;
            j++;
        }
    }

    return ans;
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

    vector<int> ans = FirstNegativeInteger(arr, n, K);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}
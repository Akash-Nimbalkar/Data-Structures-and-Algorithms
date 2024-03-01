#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k-sized window
    for (int i = 0; i < k; i++)
    {

        while (maxi.size() != 0 && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (mini.size() != 0 && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // For remaining windows
    for (int i = k; i < n; i++)
    {

        // Removal
        while (maxi.size() != 0 && i - maxi.front() >= k)
            maxi.pop_front();

        while (mini.size() != 0 && i - mini.front() >= k)
            mini.pop_front();

        // Addition
        while (maxi.size() != 0 && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (mini.size() != 0 && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}
int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;

    return 0;
}
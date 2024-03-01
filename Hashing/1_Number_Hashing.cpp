#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter no. of elements in array" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // Pre-computation
    int hash[13] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        // Fetch
        cout << num << " appears exactly " << hash[num] << " times " << endl;
    }
    return 0;
}
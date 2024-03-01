#include <bits/stdc++.h>
using namespace std;

void reverse(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    swap(arr[s], arr[e]);

    reverse(arr, s+1, e-1);
}
int main()
{

    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    reverse(arr, 0, 9);

    for (auto x : arr)
    {
        cout << x<<" ";
    }

    return 0;
}
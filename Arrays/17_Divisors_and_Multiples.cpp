#include <bits/stdc++.h>
using namespace std;
void solve(int *arr, int n)
{

    int A[20] = {0};
    for (int i = 0; i < n; i++)
    {
        int mul = 0, div = 0;
        for (int j = 0; j < n; j++)
        {

            if (arr[j] % arr[i] == 0 && i != j)
            {
                mul++;
            }
            else if (arr[i] % arr[j] == 0 && i != j)
            {
                div++;
            }
        }
        int sum = mul + div;
        cout << sum << " ";
    }
}
int main()
{
    int arr[] = {1, 3, 4, 2, 6};
    solve(arr, 5);
    return 0;
}
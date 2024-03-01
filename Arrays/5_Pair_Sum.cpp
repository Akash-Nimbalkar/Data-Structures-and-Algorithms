#include <iostream>
using namespace std;

int pair_sum(int arr[], int n, int s)
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
}
int main()
{
    int arr[20], n;
    cout << "Enter size of array" << endl;
    cin >> n;
    cout << "Enter " << n << " array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair_sum(arr, n, 5);

    return 0;
}
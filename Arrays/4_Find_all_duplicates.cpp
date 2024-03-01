// T.C. : O(N^2)

#include <iostream>
using namespace std;
void find_duplicate(int arr[], int n)
{
    int i = 0, j = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << arr[i] << " ";
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
    find_duplicate(arr, n);
    return 0;
}
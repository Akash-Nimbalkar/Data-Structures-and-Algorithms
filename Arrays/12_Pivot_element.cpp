#include <iostream>
using namespace std;
int pivotIndex(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int main()
{
    int arr[] = {3, 8, 10, 17, 1};
    int ans = (arr, 5);
    cout << "Pivot element has index " << ans << endl;

    return 0;
}
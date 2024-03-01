// Find Unique Element
#include <iostream>
using namespace std;
int unique(int arr[], int n)
{
    int un;
    for (int i = 0; i < n; i++)
    {
        un = arr[i] ^ arr[i++];
    }
    return un;
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
    int c = unique(arr, n);

    return 0;
}
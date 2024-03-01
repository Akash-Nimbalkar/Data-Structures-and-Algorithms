#include <iostream>
using namespace std;
int Sum(int arr[], int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    int sum = arr[0] + Sum(arr + 1, n - 1);
    return sum;
}
int main()
{
    int arr[20], n;
    cout << "Enter size of array " << endl;
    cin >> n;
    cout << "Enter " << n << " array elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Sum of array elements is " << Sum(arr, n);

    return 0;
}
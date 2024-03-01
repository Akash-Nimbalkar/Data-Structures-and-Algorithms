#include <bits/stdc++.h>
using namespace std;

int uniqueElement(int arr[], int size)
{
    sort(arr, arr + size);
    for (int i = 0; i < size; i = i + 2)
    {
        for (int j = i + 1; j < size; j = j + 2)
        {
            if (arr[j] == arr[i])
            {
                break;
            }
            else
            {
                return arr[i];
            }
        }
    }
}
int main()
{
    int arr[20], size;
    cout << "Enter size of array " << endl;
    cin >> size;
    cout << " Enter " << size << " elements " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int unq = uniqueElement(arr, size);
    cout << " The unique element in array is as shown :" << unq << endl;

    return 0;
}
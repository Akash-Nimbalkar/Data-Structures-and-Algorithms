#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;

    cout << "Enter no. of elements" << endl;
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " array elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << " ---> " << it.second << endl;
    }

    int num;
    cout << "Enter number" << endl;
    cin >> num;
    cout << "The number " << num << " appears exactly " << mpp[num] << " times " << endl;

    return 0;
}
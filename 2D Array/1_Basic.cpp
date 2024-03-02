#include <bits/stdc++.h>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == target)
                return true;
        }
    }
    return false;
}
int main()
{
    // 2-D Array Creation
    int arr[3][4];

    int a[4][2] = {1, 3, 5, 7, 9, 2, 4, 6};

    int b[4][2] = {{1, 11}, {2, 22}, {3, 33}, {4, 44}};

    // Taking Input Row wise
    cout << "Enter array elements" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Displaying output row wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Taking input column wise
    cout << "Enter array elements" << endl;
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            cin >> arr[row][col];
        }
    }

    // Displaying Output Column wise
    for (int col = 0; col < 4; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    cout << endl;
    // Displaying a
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    // Displaying b
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the element to search" << endl;
    int target;
    cin >> target;

    if (isPresent(arr, target, 3, 4))
    {
        cout << "Element found!!" << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }
    return 0;
}
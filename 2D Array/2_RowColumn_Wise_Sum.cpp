// To Print row wise and column wise sum of given 2D array

#include <bits/stdc++.h>
using namespace std;

void rowWiseSum(int arr[][4], int row, int col)
{
    cout << "Row wise sum : " << endl;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
}

void columnWiseSum(int arr[][4], int row, int col)
{
    cout << "Column wise sum : " << endl;
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
}

void largestRowSum(int arr[][4], int row, int col)
{
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }

        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = i;
        }
    }

    cout << "The Largest row sum is " << maxi << " for the row " << rowIndex;
}

void largestColumnSum(int arr[][4], int row, int col)
{
    int maxi = INT_MIN;
    int colIndex = -1;
    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }

        if (sum > maxi)
        {
            maxi = sum;
            colIndex = i;
        }
    }

    cout << "The Largest column sum is " << maxi << " for the column " << colIndex;
}

int main()
{
    int arr[3][4];

    cout << "Enter array elements" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    rowWiseSum(arr, 3, 4);
    cout << endl;
    columnWiseSum(arr, 3, 4);
    cout << endl;
    largestRowSum(arr, 3, 4);
    cout << endl;
    largestColumnSum(arr, 3, 4);

    return 0;
}
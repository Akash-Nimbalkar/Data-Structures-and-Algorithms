/*You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise. */

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();
    int s = 0;
    int e = row * col - 1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        int element = matrix[mid / col][mid % col];

        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            s = mid + 1;
        }
        else
        {

            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return false;
}

int main()
{

    int m, n;
    cout << "Enter no. of rows and columns " << endl;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    int target;
    cout << "Enter target element to be searched" << endl;
    cin >> target;

    if (searchMatrix(matrix, target))
    {
        cout << "Element found!!" << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }

    return 0;
}
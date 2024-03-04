/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // Find out the transpose of given matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // On swapping the first and last columns will generate the rotated image of matrix by 90°

    int s = 0, e = col - 1;

    while (s < e)
    {
        for (int i = 0; i < row; i++)
        {
            swap(matrix[i][s], matrix[i][e]);
        }
        s++;
        e--;
    }
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

    rotate(matrix);
    cout << "After rotating by 90 degrees..." << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
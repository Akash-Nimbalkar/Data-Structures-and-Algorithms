// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    int sRow = 0;
    int eRow = row - 1;
    int sCol = 0;
    int eCol = col - 1;

    while (count < total)
    {
        // Print Starting Row
        for (int i = sCol; count < total && i <= eCol; i++)
        {
            ans.push_back(matrix[sRow][i]);
            count++;
        }
        sRow++;

        // Print Ending Column
        for (int i = sRow; count < total && i <= eRow; i++)
        {
            ans.push_back(matrix[i][eCol]);
            count++;
        }
        eCol--;

        // Print Ending Row
        for (int i = eCol; count < total && i >= sCol; i--)
        {
            ans.push_back(matrix[eRow][i]);
            count++;
        }
        eRow--;

        // Print Starting Column
        for (int i = eRow; count < total && i >= sRow; i--)
        {
            ans.push_back(matrix[i][sCol]);
            count++;
        }
        sCol++;
    }
    return ans;
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
    }
    vector<int> ans = spiralOrder(matrix);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
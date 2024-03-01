#include <iostream>
using namespace std;

int celebrity()
{
    int arr[3][3] = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    bool null_row = true;
    bool unity_column = true;
    int j = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (arr[i][k] != 0)
            {
                null_row = false;
                break;
            }
            else
            {
                null_row == true;
            }
        }
        if (null_row == true)
        {
            j = i;
            cout << j;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (arr[i][j] != 1)
        {
            unity_column = false;
        }
        else if (arr[i][j] == 1 || arr[i][i] == 0)
        {
            unity_column = true;
            return j;
        }
    }
}

int main()
{
    int celeb = celebrity();
    cout << "Celebrity is " << celeb << endl;
    return 0;
}
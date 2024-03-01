//Print numbers from 1 to n by backtracking
#include <bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
    if (i < 1)
        return;

    print(i - 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    print(n, n);
    return 0;
}
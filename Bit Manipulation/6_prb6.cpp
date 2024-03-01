// Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int mask = 1 << k;

    if ((n & mask) != 0)
    {
        cout << "The kth bit is set" << endl;
    }
    else
    {
        cout << "The kth bit is not set" << endl;
    }

    return 0;
}
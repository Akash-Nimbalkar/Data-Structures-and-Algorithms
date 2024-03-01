// Given n, return the number with unsetting the first non-zero bit
// eg. 12 == 1100 so unset the 2nd bit so return 1000 == 8
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if ((n & 1) == 0)
    {
        n = n & n - 1;
    }
    else // For odd number always the 0th bit is set so we just want to unset it that means to return the number before current number.
    {
        n = n - 1;
    };

    cout << "The number after unsetting the first bit is " << n << endl;

    return 0;
}
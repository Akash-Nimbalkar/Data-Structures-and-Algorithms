// Given a range L-R, you need to print the XOR of all numbers in the range (L^L+1^L+2......^R-1^R)

#include <bits/stdc++.h>
using namespace std;
int xorOperation(int n)
{
    if (n % 4 == 0)
    {
        return n;
    }
    else if (n % 4 == 1)
    {
        return 1;
    }
    else if (n % 4 == 2)
    {
        return n + 1;
    }
    else if (n % 4 == 3)
    {
        return 0;
    }
}



int main()
{
    int l, r;
    cin >> l >> r;

    int ans = xorOperation(r) ^ xorOperation(l - 1);

    cout << ans << endl;
  

    return 0;
}
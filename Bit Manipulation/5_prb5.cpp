// Given a number N, check whether N is even or odd

#include <bits/stdc++.h>
using namespace std;

void evenOrOdd(int n)
{
    if ((n & 1) == 0) // Brackets around n&1 are needed as == has higher precedence than & so it get evaluate first resulting in
                      // 1 == 0 which is always false, to avoid this we need to put brackets
    {
        cout << n << " is even number " << endl;
    }
    else
    {
        cout << n << " is odd number " << endl;
    }
}
int main()
{
    int n;
    cin >> n;

    evenOrOdd(n);
    return 0;
}
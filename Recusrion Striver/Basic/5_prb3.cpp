//Print numbers from n to 1
#include <bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
    if (i<1)
        return;
    cout << i << endl;
    print(i - 1, n);
}
int main()
{
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    print(n, n);
    return 0;
}
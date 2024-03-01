//Print Name n times
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void print(int i, int n)
{
    if (i > n)
        return;

    cout << "STRIVER" << endl;
    cnt++;
    print(i + 1, n);
}
int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    print(1, n);
    return 0;
}
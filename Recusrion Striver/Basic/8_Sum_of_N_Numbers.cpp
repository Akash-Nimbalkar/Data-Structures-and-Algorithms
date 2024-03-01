#include <bits/stdc++.h>
using namespace std;

void parametrizedSolution(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl;
        return;
    }

    parametrizedSolution(i - 1, sum + i);
}

int functionalSolution(int n)
{
    if (n == 0)
        return 0;

    return n + functionalSolution(n - 1);
}
int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    cout << functionalSolution(n);

    return 0;
}
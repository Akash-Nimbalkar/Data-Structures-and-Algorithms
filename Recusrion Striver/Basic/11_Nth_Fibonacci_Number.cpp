#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;

    cout << "The " << n << "th "
         << "Fibonacci Number is " << fib(n) << endl;
    return 0;
}
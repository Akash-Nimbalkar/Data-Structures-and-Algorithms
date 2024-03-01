// Given N, print XOR of all numbers between 1 to N (without using loops)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: " << endl;
    cin >> n;

    // Observe patterns from 1-8

    if (n % 4 == 0)
    {
        cout << "The XOR from 1 to " << n << " is " << n << endl;
    }
    else if (n % 4 == 1)
    {
        cout << "The XOR from 1 to " << n << " is " << 1 << endl;
    }
    else if (n % 4 == 2)
    {
        cout << "The XOR from 1 to " << n << " is " << n + 1 << endl;
    }
    else if (n % 4 == 3)
    {
        cout << "The XOR from 1 to " << n << " is " << 0 << endl;
    }

    return 0;
}
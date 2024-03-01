// Swap two numbers without using temp, +,-,*,/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers" << endl;
    cin >> a >> b;

    cout << "Before Swapping..." << endl;
    cout << "a = " << a << " "
         << "b = " << b << endl;

    // Logic of Swapping
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After Swapping..." << endl;
    cout << "a = " << a << " "
         << "b = " << b << endl;
    return 0;
}
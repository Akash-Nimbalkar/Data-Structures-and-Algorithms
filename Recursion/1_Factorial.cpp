#include <iostream>
using namespace std;
int factorial(int num)
{
    if (num == 0)
        return 1;

    return num * factorial(num - 1);
}
int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    int ans = factorial(n);
    cout << "The factorial of " << n << " is " << ans << endl;

    return 0;
}
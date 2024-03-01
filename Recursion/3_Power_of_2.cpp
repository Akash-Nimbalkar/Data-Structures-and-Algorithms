#include <iostream>
using namespace std;
int power(int num)
{
    if (num == 0)
        return 1;
    return 2 * power(num - 1);
}
int main()
{
    int n;
    cout << "Enter any number" << endl;
    cin >> n;

    int ans = power(n);
    cout << "2^" << n << " = " << ans << endl;

    return 0;
}
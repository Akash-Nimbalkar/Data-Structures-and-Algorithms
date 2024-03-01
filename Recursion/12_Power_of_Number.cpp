#include <iostream>
using namespace std;

long long int power(int a, int b)
{
    if (b == 0) // Base Case
        return 1;
    if (b == 1)
        return a;

    long long int ans = power(a, b / 2); // Recursive call
    if (b % 2 == 0)
        return ans * ans;
    else
        return a * ans * ans;
}
int main()
{
    int a, b;
    cout << "Enter values" << endl;
    cin >> a >> b;
    long long int ans = power(a, b);
    cout << "Answer is " << ans << endl;

    return 0;
}